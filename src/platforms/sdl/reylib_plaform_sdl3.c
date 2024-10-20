#include "reylib.h"
#include "reylib_core_data.h"

#include "sdl3/sdl.h"

#define SDL_MAIN_HANDLED
#include "sdl3/SDL_main.h"

static SDL_Window* GameWindow = NULL;
static rlPlatformConfig* PlatformConfig = NULL;

SDL_AppResult sdlInit(void** appstate, int argc, char* argv[])
{
    if (PlatformConfig == NULL)
        return SDL_APP_FAILURE;

    GameWindow = SDL_CreateWindow(PlatformConfig->WindowName, PlatformConfig->Width, PlatformConfig->Height, SDL_WINDOW_OPENGL);

    if (PlatformConfig->Init && !PlatformConfig->Init())
        return SDL_APP_SUCCESS;

    return SDL_APP_CONTINUE;
}

SDL_AppResult sdlIterate(void* appstate)
{
    if (PlatformConfig == NULL || PlatformConfig->Render == NULL)
        return SDL_APP_FAILURE;

    bool exit = false;

    if (!PlatformConfig->Update)
        exit = PlatformConfig->Update();
    
    if (!exit)
    {
        rlBeginFrame();
        exit = PlatformConfig->Render();
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

    default:
        break;
    }

    return SDL_APP_CONTINUE;
}

void sdlShutdown(void* appstate, SDL_AppResult result)
{
    if (PlatformConfig && PlatformConfig->Shutdown)
    {
        PlatformConfig->Shutdown();
    }
}

void rlPlatformInitApp(rlPlatformConfig* config)
{
    PlatformConfig = config;

    SDL_Init(SDL_INIT_VIDEO);

    if (PlatformConfig->Render)
    {
        SDL_EnterAppMainCallbacks(0, NULL, sdlInit, sdlIterate, sdlEvent, sdlShutdown);
        return;
    }

    sdlInit(NULL, 0, NULL);
}

void rlPlatformShutdown()
{
    SDL_DestroyWindow(GameWindow);
    GameWindow = NULL;
}

void rlPlatformBeginFrame()
{

}

void rlPlatformEndFrame()
{
    SDL_GL_SwapWindow(GameWindow);

    if (PlatformConfig->Render)
        return;

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        sdlEvent(NULL, &event);
    }
}