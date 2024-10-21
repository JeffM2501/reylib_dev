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
    rlDrawRectangleAtPosition(RLPoint2FZeros, rectangle, color);
}

static inline void SetRenderColor(RLColor color)
{
    SDL_SetRenderDrawColor(rlPlatformWindowState.GameRenderer, color.R, color.G, color.B, color.A);
}

void rlDrawRectangleAtPosition(RLPoint2F point, RLRectangle2F rectangle, RLColor color)
{
    SetRenderColor(color);
    SDL_FRect rect = { point.X + rectangle.Origin.X, point.Y + rectangle.Origin.Y, rectangle.Size.X, rectangle.Size.Y };

    SDL_RenderFillRect(rlPlatformWindowState.GameRenderer, &rect);
}