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

    SDL_FRect destRect = { point.X, point.Y, rectangle.Width, rectangle.Height };

    SDL_RenderFillRect(rlPlatformWindowState.GameRenderer, &destRect);
}

void rlDrawTexture(RLTexture texture, RLRectangle2F sourceRect, RLRectangle2F destRect, RLColor tint)
{
    SDL_SetTextureColorMod((SDL_Texture*)texture.Texture, tint.R, tint.G, tint.B);
    SDL_SetTextureAlphaMod((SDL_Texture*)texture.Texture, tint.A);

    SDL_RenderTexture(rlPlatformWindowState.GameRenderer, (SDL_Texture*)texture.Texture, (SDL_FRect*)&sourceRect, (SDL_FRect*)&destRect);
}

void rlDrawTextureAtPosition(RLTexture texture, RLPoint2F point, RLColor tint)
{
    rlDrawTexture(texture, texture.Bounds, (RLRectangle2F) { point.X, point.Y, texture.Bounds.Width, texture.Bounds.Height }, tint);
}