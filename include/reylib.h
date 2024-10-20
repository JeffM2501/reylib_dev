#pragma once

#include <stdint.h>
#include <stdbool.h>

#if defined(__cplusplus)
extern "C" {            // Prevents name mangling of functions
#endif

#define RL_API
    typedef bool(*FrameCallback)(void);

    RL_API void rlInitApp(uint32_t width, uint32_t height, const char* name, uint32_t flags, FrameCallback updateCallback, FrameCallback renderCallback, FrameCallback initCallback, FrameCallback shutdownCallback);
    RL_API void rlInitAppSimple(uint32_t width, uint32_t height, const char* name, uint32_t flags);

    RL_API void rlShutdown();

    RL_API void rlBeginFrame();
    RL_API void rlEndFrame();

    RL_API bool rlWantExit();

#if defined(__cplusplus)
}
#endif