#include "reylib_drawing.h"
#include "reylib_core_data.h"

#include "platforms/reylib_platform.h"

void rlClearBackgroud(RLColor color)
{
    SDL_SetRenderDrawColor(rlPlatformWindowState.GameRenderer, color.R, color.G, color.B, color.A);
    SDL_RenderClear(rlPlatformWindowState.GameRenderer);
}

void rlDrawRectangle(RLRectangle2F rectangle, RLColor color)
{
    rlDrawRectangleAtPosition(rectangle, RLPoint2FZeros, color);
}

static inline void SetRenderColor(RLColor color)
{
    SDL_SetRenderDrawColor(rlPlatformWindowState.GameRenderer, color.R, color.G, color.B, color.A);
}

void rlDrawRectangleAtPosition(RLRectangle2F rectangle, RLPoint2F point,RLColor color)
{
    SetRenderColor(color);

    SDL_FRect destRect = { point.X + rectangle.X, point.Y + rectangle.Y, rectangle.Width, rectangle.Height };

    SDL_RenderFillRect(rlPlatformWindowState.GameRenderer, &destRect);
}

void rlDrawTexture(RLTexture texture, RLRectangle2F destRect, RLColor tint)
{
    SDL_SetTextureColorMod((SDL_Texture*)texture.Texture, tint.R, tint.G, tint.B);
    SDL_SetTextureAlphaMod((SDL_Texture*)texture.Texture, tint.A);

    SDL_RenderTexture(rlPlatformWindowState.GameRenderer,
        (SDL_Texture*)texture.Texture,
        (SDL_FRect*)&texture.Bounds,
        (SDL_FRect*)&destRect);
}
void rlDrawTextureRect(RLTexture texture, RLRectangle2F sourceRect, RLRectangle2F destRect, RLColor tint)
{
    SDL_SetTextureColorMod((SDL_Texture*)texture.Texture, tint.R, tint.G, tint.B);
    SDL_SetTextureAlphaMod((SDL_Texture*)texture.Texture, tint.A);

    SDL_RenderTexture(rlPlatformWindowState.GameRenderer,
        (SDL_Texture*)texture.Texture,
        (SDL_FRect*)&sourceRect,
        (SDL_FRect*)&destRect);
}

void rlDrawTextureAtPosition(RLTexture texture, RLPoint2F point, RLColor tint)
{
    rlDrawTextureRect(texture, 
        texture.Bounds,
        (RLRectangle2F) { point.X, point.Y, texture.Bounds.Width, texture.Bounds.Height },
        tint);
}

void rlDrawTextureAtTransform(RLTexture texture, RLTransform2D transform, RLPoint2F center, RLColor tint)
{
    SDL_SetTextureColorMod((SDL_Texture*)texture.Texture, tint.R, tint.G, tint.B);
    SDL_SetTextureAlphaMod((SDL_Texture*)texture.Texture, tint.A);

    SDL_FRect destRect = { transform.Translation.X, transform.Translation.Y, fabsf(texture.Bounds.Width * transform.Scale.X), fabsf(texture.Bounds.Height * transform.Scale.Y) };

    SDL_RenderTextureRotated(rlPlatformWindowState.GameRenderer, 
        (SDL_Texture*)texture.Texture, 
        (SDL_FRect*)&texture.Bounds,
        &destRect,
        (double)transform.Rotation,
        (SDL_FPoint*)&center, 
        SDL_FLIP_NONE);
}

void rlDrawTextureRectAtTransform(RLTexture texture, RLRectangle2F sourceRect, RLTransform2D transform, RLPoint2F center, RLColor tint)
{
    SDL_SetTextureColorMod((SDL_Texture*)texture.Texture, tint.R, tint.G, tint.B);
    SDL_SetTextureAlphaMod((SDL_Texture*)texture.Texture, tint.A);

    SDL_FRect destRect = { transform.Translation.X, transform.Translation.Y, fabsf(sourceRect.Width * transform.Scale.X), fabsf(sourceRect.Height * transform.Scale.Y)};

    SDL_FlipMode mode = SDL_FLIP_NONE;
    if (sourceRect.Width < 0)
        mode |= SDL_FLIP_HORIZONTAL;
    if (sourceRect.Height < 0)
        mode |= SDL_FLIP_VERTICAL;

    SDL_RenderTextureRotated(rlPlatformWindowState.GameRenderer,
        (SDL_Texture*)texture.Texture,
        (SDL_FRect*)&texture.Bounds,
        &destRect,
        (double)transform.Rotation,
        (SDL_FPoint*)&center,
        mode);
}