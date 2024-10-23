#pragma once

#include "reylib_lib_utils.h"
#include "reylib_geometry_types.h"

#if defined(__cplusplus)
extern "C" {            // Prevents name mangling of functions
#endif

    RL_API RLVector2F rlGetWindowSize();
    RL_API RLPoint2F rlGetWindowPosition();

    RL_API bool rlWasWindowMoved();
    RL_API bool rlWasWindowResized();

#if defined(__cplusplus)
}
#endif