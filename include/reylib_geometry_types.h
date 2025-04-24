#pragma once

#include "reylib_lib_utils.h"

// 2d Vector that uses floats
typedef struct RLVector2F
{
    float X;
    float Y;
#if defined(__cplusplus)
    RLVector2F(int x, int y)
        : X(x), Y(y){ }

    RLVector2F(float x = 0, float y = 0)
        : X(x), Y(y) { }

    static constexpr RLVector2F Zeros() { return RLVector2F(0, 0); }
    static constexpr RLVector2F Ones() { return RLVector2F(1, 1); }
    static constexpr RLVector2F UnitX() { return RLVector2F(1, 0); }
    static constexpr RLVector2F UnitY() { return RLVector2F(0, 1); }
#endif
}RLVector2F;

typedef RLVector2F RLPoint2F;

#define RLVector2FZeros  CLITERAL(RLVector2F){ 0, 0 }
#define RLVector2FOnes   CLITERAL(RLVector2F){ 1, 1 }
#define RLVector2FUnitX  CLITERAL(RLVector2F){ 1, 0 }
#define RLVector2FUnitY  CLITERAL(RLVector2F){ 0, 1 }

#define RLPoint2FZeros   CLITERAL(RLPoint2F){ 0, 0 }

// 2d Rectangle that uses floats
typedef struct RLRectangle2F
{
    float X, Y, Width, Height;
#if defined(__cplusplus)
    RLRectangle2F(int x, int y, int w, int h)
        : X(x), Y(y), Width(w), Height(h) { }

    RLRectangle2F(float x = 0, float y = 0, float w = 0, float h = 0)
        : X(x), Y(y), Width(w), Height(h) { }
#endif
}RLRectangle2F;

#define RLRectangle2FZeroes  CLITERAL(RLRectangle2F){ 0, 0, 0, 0 }


typedef struct RLTransform2D
{
    RLPoint2F Translation;
    float Rotation;
    RLVector2F Scale;

#if defined(__cplusplus)
    RLTransform2D()
        : Translation(0,0), Rotation(0), Scale(1,1){
    }

    RLTransform2D(const RLPoint2F& translation)
        : Translation(translation), Rotation(0), Scale(1, 1) {
    }

    RLTransform2D(const RLPoint2F& translation, const float& rotation)
        : Translation(translation), Rotation(rotation), Scale(1, 1) {
    }
#endif
}RLTransform2D;

#if defined(__cplusplus)
}
#endif