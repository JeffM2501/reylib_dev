#pragma once

#include "reylib_lib_utils.h"
#include "reylib_colors.h"
#include "reylib_geometry_types.h"
#include "reylib_textures.h"

#if defined(__cplusplus)
extern "C" {            // Prevents name mangling of functions
#endif

    RL_API void rlClearBackgroud(RLColor color);

    RL_API void rlDrawRectangle(RLRectangle2F rectangle, RLColor color);
    RL_API void rlDrawRectangleAtPosition(RLRectangle2F rectangle, RLPoint2F point, RLColor color);

    RL_API void rlDrawTexture(RLTexture texture, RLRectangle2F sourceRect, RLRectangle2F destRect, RLColor tint);
    RL_API void rlDrawTextureAtPosition(RLTexture texture, RLPoint2F point, RLColor tint);

#if defined(__cplusplus)
}
#endif