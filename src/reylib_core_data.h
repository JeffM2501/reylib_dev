#pragma once

#include <stdbool.h>

#include "reylib_geometry_types.h"

typedef struct RLCoreData
{
    bool    WantClose;
    double  LastFrameTime;
    float  DeltaTime;
}RLCoreData;

extern RLCoreData rlCoreData;