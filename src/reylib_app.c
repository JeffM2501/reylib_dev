#include "reylib.h"
#include "reylib_core_data.h"
#include "platforms/reylib_platform.h"

RLCoreData rlCoreData;

RLPlatformConfig rlPlatformConfig = { 0 };
RLPlaformWindowState rlPlatformWindowState = { 0 };

void sdlUpdateKeyboardFrame();

static void rlInitCoreData()
{
    rlCoreData.WantClose = false;
}

void rlInitApp(uint32_t width, uint32_t height, const char* name, uint32_t flags, FrameCallback updateCallback, FrameCallback renderCallback, FrameCallback initCallback, FrameCallback shutdownCallback)
{
    rlInitCoreData();

    rlPlatformConfig.Width = width;
    rlPlatformConfig.Height = height;
    rlPlatformConfig.Init = initCallback;
    rlPlatformConfig.Update = updateCallback;
    rlPlatformConfig.Render = renderCallback;
    rlPlatformConfig.Shutdown = shutdownCallback;
    rlPlatformConfig.Flags = flags;

    strcpy(rlPlatformConfig.WindowName, name);


    SDL_Init(SDL_INIT_VIDEO);

    if (rlPlatformConfig.Render)
    {
        SDL_EnterAppMainCallbacks(0, NULL, sdlInit, sdlIterate, sdlEvent, sdlShutdown);
        return;
    }

    sdlInit(NULL, 0, NULL);
}

void rlInitAppSimple(uint32_t width, uint32_t height, const char* name, uint32_t flags)
{
    rlInitApp(width, height, name, flags, NULL, NULL, NULL, NULL);
}

void rlShutdown()
{
    if (rlPlatformWindowState.GameRenderer)
        SDL_DestroyRenderer(rlPlatformWindowState.GameRenderer);
    if (rlPlatformWindowState.GameWindow)
        SDL_DestroyWindow(rlPlatformWindowState.GameWindow);

    rlPlatformWindowState.GameWindow = NULL;
    rlPlatformWindowState.GameRenderer = NULL;
}

void rlBeginFrame()
{
    // setup default projection matrix
}

void ClearEndOffFrameData()
{
    rlCoreData.WantClose = false;

    rlPlatformWindowState.WasWindowMoved = false;
    rlPlatformWindowState.WasWindowResized = false;

    rlPlatformWindowState.MouseDelta.X = 0;
    rlPlatformWindowState.MouseDelta.Y = 0;

    sdlUpdateKeyboardFrame();
}

void rlEndFrame()
{
    ClearEndOffFrameData();

    SDL_RenderPresent(rlPlatformWindowState.GameRenderer);

    if (rlPlatformConfig.Render)
        return;

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        sdlEvent(NULL, &event);
    }
    
    // do end frame work (like waiting)

    double now = rlGetTime();
    rlCoreData.DeltaTime = (float)(now - rlCoreData.LastFrameTime);
    rlCoreData.LastFrameTime = now;
}

bool rlWantExit()
{
    return rlCoreData.WantClose;
}

double rlGetTime()
{
    return SDL_GetTicks() / 1000.0;
}

float rlGetFrameTime()
{
    return rlCoreData.DeltaTime;
}