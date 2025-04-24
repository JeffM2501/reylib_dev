#pragma once

#include "reylib_lib_utils.h"
#include "reylib_colors.h"
#include "reylib_geometry_types.h"
#include "reylib_textures.h"

#if defined(__cplusplus)
extern "C" {            // Prevents name mangling of functions
#endif

    /// <summary>
    /// Clear the current render target with a color
    /// </summary>
    /// <param name="color">The color to clear</param>
    RL_API void rlClearBackgroud(RLColor color);

    /// <summary>
    /// Draw a filled colored rectangle
    /// </summary>
    /// <param name="rectangle">The bounding rectangle to draws</param>
    /// <param name="color">The fill color</param>
    RL_API void rlDrawRectangle(RLRectangle2F rectangle, RLColor color);

    /// <summary>
    /// Draw a solid rectangle relative to a specific point. The rectangle X,Y origin will be added to the provided point
    /// </summary>
    /// <param name="rectangle">The relative rectangle to draw </param>
    /// <param name="point">The point to draw the rectangle at</param>
    /// <param name="color">The fill color</param>
    RL_API void rlDrawRectangleAtPosition(RLRectangle2F rectangle, RLPoint2F point, RLColor color);

    /// <summary>
    /// Draw an entire texture to a destination rectangle in the render target
    /// </summary>
    /// <param name="texture">Texture to draw</param>
    /// <param name="destRect">The destination rect to fit the texture too</param>
    /// <param name="tint">A color to tint the texture with</param>
    RL_API void rlDrawTexture(RLTexture texture, RLRectangle2F destRect, RLColor tint);

    /// <summary>
    /// Draws part of a texture to a destination rectangle in the render target
    /// </summary>
    /// <param name="texture">Texture to draw</param>
    /// <param name="sourceRect">The local source rect that defines the part of the texture to draw from</param>
    /// <param name="destRect">The destination rect to fit the texture too</param>
    /// <param name="tint">A color to tint the texture with</param>
    RL_API void rlDrawTextureRect(RLTexture texture, RLRectangle2F sourceRect, RLRectangle2F destRect, RLColor tint);

    /// <summary>
    /// Draws an entire texture at a location in the render target at its original size
    /// </summary>
    /// <param name="texture">Texture to draw</param>
    /// <param name="point">The locationt to draw the texture at (upper left as origin)</param>
    /// <param name="tint">A color to tint the texture with</param>
    RL_API void rlDrawTextureAtPosition(RLTexture texture, RLPoint2F point, RLColor tint);

    /// <summary>
    /// Draws part of a texture to a destination rectangle in the render target at a location in the render target at its original size
    /// </summary>
    /// <param name="texture">Texture to draw</param>
    /// <param name="point">The locationt to draw the texture at (upper left as origin)</param>
    /// <param name="tint">A color to tint the texture with</param>
    RL_API void rlDrawTextureRectAtPosition(RLTexture texture, RLPoint2F point, RLColor tint);

    /// <summary>
    ///  Draws an entire texture at a location, rotation, and scale in the render target
    /// </summary>
    /// <param name="texture">Texture to draw</param>
    /// <param name="transform">The transformation (location, rotation, and scale), to draw the texture at</param>
    /// <param name="center">The relative pivot point offset of the texture (at destination scale)</param>
    /// <param name="tint">A color to tint the texture with</param>
    RL_API void rlDrawTextureAtTransform(RLTexture texture, RLTransform2D transform, RLPoint2F center, RLColor tint);

    /// <summary>
    /// Draws part of a texture to a destination rectangle in the render target at a location, rotation, and scale in the render target
    /// </summary>
    /// <param name="texture">Texture to draw</param>
    /// <param name="sourceRect">The local source rect that defines the part of the texture to draw from</param>
    /// <param name="transform">The transformation (location, rotation, and scale), to draw the texture at</param>
    /// <param name="center">The relative pivot point offset of the texture (at destination scale)</param>
    /// <param name="tint">A color to tint the texture with</param>
    RL_API void rlDrawTextureRectAtTransform(RLTexture texture, RLRectangle2F sourceRect, RLTransform2D transform, RLPoint2F center, RLColor tint);

#if defined(__cplusplus)
}
#endif