#include "reylib_display.h"
#include "reylib_core_data.h"

#include "platforms/reylib_platform.h"

RLVector2F rlGetWindowSize()
{
    return rlPlatformWindowState.WindowSize;
}

RLPoint2F rlGetWindowPosition()
{
    return rlPlatformWindowState.WindowPosition;
}

bool rlWasWindowMoved()
{
    return rlPlatformWindowState.WasWindowMoved;
}

bool rlWasWindowResized()
{
    return rlPlatformWindowState.WasWindowResized;
}