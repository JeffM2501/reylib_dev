#pragma once

#include "reylib_app.h"
#include "reylib_geometry_types.h"

 // SDL Platform data

#include "sdl3/sdl.h"

#define SDL_MAIN_HANDLED
#include "sdl3/SDL_main.h"

#define MAX_WINDOW_NAME_SIZE 256

typedef struct RLPlatformConfig
{
    FrameCallback Init;
    FrameCallback Update;
    FrameCallback Render;
    FrameCallback Shutdown;

    uint32_t Flags;

    char WindowName[MAX_WINDOW_NAME_SIZE];

    uint32_t Width;
    uint32_t Height;
}RLPlatformConfig;
extern RLPlatformConfig rlPlatformConfig;

typedef struct RLPlaformWindowState
{
    SDL_Window* GameWindow;
    SDL_Renderer* GameRenderer;

    RLPoint2F MousePosition;
    RLPoint2F MouseDelta;

    RLPoint2F WindowPosition;
    RLPoint2F WindowSize;

    bool WasWindowResized;
    bool WasWindowMoved;

}RLPlaformWindowState;
extern RLPlaformWindowState rlPlatformWindowState;

SDL_AppResult sdlInit(void** appstate, int argc, char* argv[]);

SDL_AppResult sdlIterate(void* appstate);

SDL_AppResult sdlEvent(void* appstate, SDL_Event* event);

void sdlShutdown(void* appstate, SDL_AppResult result);