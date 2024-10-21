#pragma once

#include "reylib_lib_utils.h"

// 2d Vector that uses floats
typedef struct RLPRLVector2Foint2F
{
    float X;
    float Y;
#if defined(__cplusplus)
    RLVector2F(int x, int y)
        : X(x), Y(y){ }

    RLVector2F(float x = 0, float y = 0)
        : X(x), Y(y) { }
#endif
}RLVector2F;

typedef RLVector2F RLPoint2F;

#define RLVector2FZeros  CLITERAL(RLVector2F){ 0, 0 }
#define RLVector2FOnes  CLITERAL(RLVector2F){ 1, 1 }
#define RLVector2FUnitX  CLITERAL(RLVector2F){ 1, 0 }
#define RLVector2FUnitY  CLITERAL(RLVector2F){ 0, 1 }

#define RLPoint2FZeros  CLITERAL(RLPoint2F){ 0, 0 }

// 2d Rectangle that uses floats
typedef struct RLRectangle2F
{
    RLPoint2F Origin;
    RLVector2F Size;
#if defined(__cplusplus)
    RLRectangle2F(int x, int y, int w, int h)
        : Origin(x,y), Size(w,h) { }

    RLRectangle2F(float x = 0, float y = 0, float w = 0, float h = 0)
        : Origin(x, y), Size(w, h) { }
#endif
}RLRectangle2F;

#define RLRectangle2FZeroes  CLITERAL(RLRectangle2F){ {0, 0}, {0, 0} }
