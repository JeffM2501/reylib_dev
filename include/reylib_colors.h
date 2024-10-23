#pragma once

#include "reylib_lib_utils.h"

// Color, 4 components, R8G8B8A8 (32bit)
typedef struct RLColor
{
    unsigned char R;        // Color red value
    unsigned char G;        // Color green value
    unsigned char B;        // Color blue value
    unsigned char A;        // Color alpha value

#if defined(__cplusplus)
    RLColor(unsigned char r = 255, unsigned char b = 255, unsigned char b = 255, unsigned char a = 255)
        : R(r), G(g), B(b), A(a)  { }

    RLColor(float r, float b, float b, float a = 1)
        : R(unsigned char(r* 255)), G(unsigned char(g * 255)), B(unsigned char(b * 255)), A(unsigned char(a * 255)) { }

    // TODO operators?
#endif
}RLColor;

RL_API inline uint32_t rlColorToInt(RLColor color)
{
    return (((uint32_t)color.R << 24) | ((uint32_t)color.G << 16) | ((uint32_t)color.B << 8) | (uint32_t)color.A);
}


// Some Basic Colors
// NOTE: Custom raylib color palette for amazing visuals on WHITE background
#define LIGHTGRAY  CLITERAL(RLColor){ 200, 200, 200, 255 }   // Light Gray
#define GRAY       CLITERAL(RLColor){ 130, 130, 130, 255 }   // Gray
#define DARKGRAY   CLITERAL(RLColor){ 80, 80, 80, 255 }      // Dark Gray
#define YELLOW     CLITERAL(RLColor){ 253, 249, 0, 255 }     // Yellow
#define GOLD       CLITERAL(RLColor){ 255, 203, 0, 255 }     // Gold
#define ORANGE     CLITERAL(RLColor){ 255, 161, 0, 255 }     // Orange
#define PINK       CLITERAL(RLColor){ 255, 109, 194, 255 }   // Pink
#define RED        CLITERAL(RLColor){ 230, 41, 55, 255 }     // Red
#define MAROON     CLITERAL(RLColor){ 190, 33, 55, 255 }     // Maroon
#define GREEN      CLITERAL(RLColor){ 0, 228, 48, 255 }      // Green
#define LIME       CLITERAL(RLColor){ 0, 158, 47, 255 }      // Lime
#define DARKGREEN  CLITERAL(RLColor){ 0, 117, 44, 255 }      // Dark Green
#define SKYBLUE    CLITERAL(RLColor){ 102, 191, 255, 255 }   // Sky Blue
#define BLUE       CLITERAL(RLColor){ 0, 121, 241, 255 }     // Blue
#define DARKBLUE   CLITERAL(RLColor){ 0, 82, 172, 255 }      // Dark Blue
#define PURPLE     CLITERAL(RLColor){ 200, 122, 255, 255 }   // Purple
#define VIOLET     CLITERAL(RLColor){ 135, 60, 190, 255 }    // Violet
#define DARKPURPLE CLITERAL(RLColor){ 112, 31, 126, 255 }    // Dark Purple
#define BEIGE      CLITERAL(RLColor){ 211, 176, 131, 255 }   // Beige
#define BROWN      CLITERAL(RLColor){ 127, 106, 79, 255 }    // Brown
#define DARKBROWN  CLITERAL(RLColor){ 76, 63, 47, 255 }      // Dark Brown

#define WHITE      CLITERAL(RLColor){ 255, 255, 255, 255 }   // White
#define BLACK      CLITERAL(RLColor){ 0, 0, 0, 255 }         // Black
#define BLANK      CLITERAL(RLColor){ 0, 0, 0, 0 }           // Blank (Transparent)
#define MAGENTA    CLITERAL(RLColor){ 255, 0, 255, 255 }     // Magenta
#define RAYWHITE   CLITERAL(RLColor){ 245, 245, 245, 255 }   // My own White (raylib logo)