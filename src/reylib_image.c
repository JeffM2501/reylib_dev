#include "reylib_image.h"
#include "platforms/reylib_platform.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

RLImage rlNewImage(uint32_t width, uint32_t height, bool hasAlpha, RLColor background)
{
    SDL_Surface* surface = SDL_CreateSurface(width, height, hasAlpha ? SDL_PIXELFORMAT_RGBA8888 : SDL_PIXELFORMAT_RGB24);
    SDL_FillSurfaceRect(surface, NULL, rlColorToInt(background));

    RLImage image;
    image.Width = width;
    image.Height = height;
    image.Image = surface;

    return image;
}

RLImage rlLoadImageFile(const char* filePath)
{
    static RLImage returnImage;
    int chanels = 0;

    stbi_uc* buffer = stbi_load(filePath, &returnImage.Width, &returnImage.Height, &chanels, 0);
    if (!buffer)
        return returnImage;

    SDL_PixelFormat pixelFormat = SDL_PIXELFORMAT_UNKNOWN;
    switch (chanels)
    {
    default:
        return returnImage;

    case 1:
        pixelFormat = SDL_PIXELFORMAT_INDEX8;
        break;
    case 3:
        pixelFormat = SDL_PIXELFORMAT_RGB24;
        break;

    case 4:
        pixelFormat = SDL_PIXELFORMAT_RGBA32;
        break;
    }

    SDL_Surface* surface = SDL_CreateSurfaceFrom(returnImage.Width, returnImage.Height, pixelFormat, buffer, returnImage.Width * chanels);

    if (!surface)
        return returnImage;

    returnImage.Image = surface;
    return returnImage;
}

void rlDestoryImage(RLImage image)
{
    if (image.Image == NULL)
        return;

    SDL_Surface* surface = (SDL_Surface*)image.Image;
    if ((surface->flags & SDL_SURFACE_PREALLOCATED) != SDL_SURFACE_PREALLOCATED)
        stbi_image_free(surface->pixels);

    SDL_DestroySurface((SDL_Surface*)image.Image);
}
