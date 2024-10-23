#include "reylib_textures.h"

#include "reylib_core_data.h"
#include "platforms/reylib_platform.h"

RLTexture rlLoadTexture(const char* filePath)
{
    RLImage image = rlLoadImageFile(filePath);
    RLTexture texture = rlLoadTextureFromImage(image);
    rlDestoryImage(image);
    return texture;
}

RLTexture rlLoadTextureFromImage(RLImage image)
{
    RLTexture texture = { 0 };

    if (image.Image == NULL)
        return texture;

    SDL_Texture* platformTexture = SDL_CreateTextureFromSurface(rlPlatformWindowState.GameRenderer, (SDL_Surface*)image.Image);

    texture.Bounds.X = 0;
    texture.Bounds.Y = 0;
    texture.Bounds.Width = (float)image.Width;
    texture.Bounds.Height = (float)image.Height;
    texture.Texture = platformTexture;

    return texture;
}

void rlDestoryTexture(RLTexture texture)
{
    if (texture.Texture != NULL)
        SDL_DestroyTexture((SDL_Texture*)texture.Texture);
}