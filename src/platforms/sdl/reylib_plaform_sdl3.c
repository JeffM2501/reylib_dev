#include "reylib.h"
#include "reylib_core_data.h"

#include "platforms/reylib_platform.h"

SDL_AppResult sdlInit(void** appstate, int argc, char* argv[])
{
    rlPlatformWindowState.GameWindow = SDL_CreateWindow(rlPlatformConfig.WindowName, rlPlatformConfig.Width, rlPlatformConfig.Height, SDL_WINDOW_OPENGL);

    if (!rlPlatformWindowState.GameWindow)
        return SDL_APP_FAILURE;

    rlPlatformWindowState.GameRenderer = SDL_CreateRenderer(rlPlatformWindowState.GameWindow, NULL);

    if (!rlPlatformWindowState.GameRenderer)
        return SDL_APP_FAILURE;

    if (rlPlatformConfig.Init && rlPlatformConfig.Init())
        return SDL_APP_SUCCESS;

    SDL_GetMouseState(&rlPlatformWindowState.MousePosition.X, &rlPlatformWindowState.MousePosition.Y);

    rlCoreData.LastFrameTime = rlGetTime();
    rlCoreData.DeltaTime = 0;

    return SDL_APP_CONTINUE;
}

SDL_AppResult sdlIterate(void* appstate)
{
    if (rlPlatformConfig.Render == NULL)
        return SDL_APP_FAILURE;

    double now = rlGetTime();
    rlCoreData.DeltaTime = (float)(now - rlCoreData.LastFrameTime);
    rlCoreData.LastFrameTime = now;

    bool exit = false;

    if (rlPlatformConfig.Update)
        exit = rlPlatformConfig.Update();
    
    if (!exit)
    {
        rlBeginFrame();
        exit = rlPlatformConfig.Render();
        rlEndFrame();
    }

    return exit ? SDL_APP_SUCCESS : SDL_APP_CONTINUE;
}

SDL_AppResult sdlEvent(void* appstate, SDL_Event* event)
{
    switch (event->type)
    {
    case SDL_EVENT_QUIT:
        rlCoreData.WantClose = true;
        break;

    case SDL_EVENT_MOUSE_MOTION:
        rlPlatformWindowState.MousePosition.X = event->motion.x;
        rlPlatformWindowState.MousePosition.Y = event->motion.y;
        rlPlatformWindowState.MouseDelta.X = event->motion.xrel;
        rlPlatformWindowState.MouseDelta.Y = event->motion.yrel;
        break;

    case SDL_EVENT_WINDOW_RESIZED:
        rlPlatformWindowState.WindowSize.X = (float)event->window.data1;
        rlPlatformWindowState.WindowSize.Y = (float)event->window.data2;
        rlPlatformWindowState.WasWindowResized = true;
        break;

    case SDL_EVENT_WINDOW_MOVED:
        rlPlatformWindowState.WindowPosition.X = (float)event->window.data1;
        rlPlatformWindowState.WindowPosition.Y = (float)event->window.data2;
        rlPlatformWindowState.WasWindowMoved = true;
        break;

    default:
        break;
    }

    return SDL_APP_CONTINUE;
}

void sdlShutdown(void* appstate, SDL_AppResult result)
{
    if (rlPlatformConfig.Shutdown)
    {
        rlPlatformConfig.Shutdown();
    }
}
