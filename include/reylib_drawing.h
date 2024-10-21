#pragma once

#include "reylib_lib_utils.h"
#include "reylib_colors.h"
#include "reylib_geometry_types.h"

#if defined(__cplusplus)
extern "C" {            // Prevents name mangling of functions
#endif

    RL_API void rlClearBackgroud(RLColor color);

    RL_API void rlDrawRectangle(RLRectangle2F rectangle, RLColor color);
    RL_API void rlDrawRectangleAtPosition(RLPoint2F point, RLRectangle2F rectangle, RLColor color);

#if defined(__cplusplus)
}
#endif