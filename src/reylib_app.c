#include "reylib.h"
#include "reylib_core_data.h"
#include "platforms/reylib_platform.h"

static RLCoreData rlCoreData;

static rlPlatformConfig platformConfig = { 0 };

static void rlInitCoreData()
{
    rlCoreData.WantClose = false;
}

void rlInitApp(uint32_t width, uint32_t height, const char* name, uint32_t flags, FrameCallback updateCallback, FrameCallback renderCallback, FrameCallback initCallback, FrameCallback shutdownCallback)
{
    rlInitCoreData();

    platformConfig.Width = width;
    platformConfig.Height = height;
    platformConfig.Init = initCallback;
    platformConfig.Update = updateCallback;
    platformConfig.Render = renderCallback;
    platformConfig.Shutdown = shutdownCallback;
    platformConfig.Flags = flags;

    strcpy(platformConfig.WindowName, name);

    rlPlatformInitApp(&platformConfig);
}

void rlInitAppSimple(uint32_t width, uint32_t height, const char* name, uint32_t flags)
{
    rlInitApp(width, height, name, flags, NULL, NULL, NULL, NULL);
}

void rlShutdown()
{
    rlPlatformShutdown();
}

void rlBeginFrame()
{
    rlPlatformBeginFrame();

    // setup default projection matrix
}

void rlEndFrame()
{
    rlCoreData.WantClose = false;

    rlPlatformEndFrame();
    
    // do end frame work (like waiting)
}

bool rlWantExit()
{
    return rlCoreData.WantClose;
}