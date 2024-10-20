#pragma once

// platform abstract headers

#define MAX_WINDOW_NAME_SIZE 256

typedef struct rlPlatformConfig
{
    FrameCallback Init;
    FrameCallback Update;
    FrameCallback Render;
    FrameCallback Shutdown;

    uint32_t Flags;

    char WindowName[MAX_WINDOW_NAME_SIZE];

    uint32_t Width;
    uint32_t Height;
}rlPlatformConfig;

void rlPlatformInitApp(rlPlatformConfig* config);
void rlPlatformShutdown();
void rlPlatformBeginFrame();
void rlPlatformEndFrame();

// TODO add other platforms

#include "platforms/sdl/reylib_plaform_sdl3.c"