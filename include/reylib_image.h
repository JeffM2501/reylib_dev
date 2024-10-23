#pragma once

#include "reylib_lib_utils.h"
#include "reylib_geometry_types.h"
#include "reylib_colors.h"

#if defined(__cplusplus)
extern "C" {            // Prevents name mangling of functions
#endif

    typedef struct
    {
        void* Image;

        uint32_t Width;
        uint32_t Height;
    }RLImage;

    RL_API RLImage rlNewImage(uint32_t width, uint32_t height, bool hasAlpha, RLColor background);
    RL_API RLImage rlLoadImageFile(const char* filePath);

    RL_API void rlDestoryImage(RLImage image);

#if defined(__cplusplus)
}
#endif