#pragma once

#include "reylib_lib_utils.h"
#include "reylib_image.h"
#

#if defined(__cplusplus)
extern "C" {            // Prevents name mangling of functions
#endif
    typedef struct RLTexture
    {
        void* Texture;
        RLRectangle2F Bounds;
    }RLTexture;

    RL_API RLTexture rlLoadTexture(const char* filePath);
    RL_API RLTexture rlLoadTextureFromImage(RLImage image);

    RL_API void rlDestoryTexture(RLTexture texture);

#if defined(__cplusplus)
}
#endif