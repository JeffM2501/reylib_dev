#include "reylib_input_keyboard.h"

#include "platforms/reylib_platform.h"

RLPlaformKeyboardState rlPlatformKeyboardState = { 0 };

void sdlProcessKeyEvents(SDL_Event* event)
{
    switch (event->type)
    {
    default:
        break;

    case SDL_EVENT_KEY_UP:
    case SDL_EVENT_KEY_DOWN:
        RLKeyboardPhysicalKey pyKey = (RLKeyboardPhysicalKey)event->key.scancode;
        rlPlatformKeyboardState.ThisFrameKeys[pyKey] = event->key.down;
        rlPlatformKeyboardState.KeyEventMap[rlPlatformKeyboardState.KeyEventMapSize].Key = pyKey;
        rlPlatformKeyboardState.KeyEventMap[rlPlatformKeyboardState.KeyEventMapSize].Down = event->key.down;
        break;
    }
}

void sdlUpdateKeyboardFrame()
{
    for (uint16_t i = 0; i < RLPK_MAX; i++)
    {
        rlPlatformKeyboardState.LastFrameKeys[i] = rlPlatformKeyboardState.ThisFrameKeys[i];
    }

    rlPlatformKeyboardState.KeyEventMapSize = 0;
}

bool rlIsPhysicalKeyDown(RLKeyboardPhysicalKey key)
{
    return rlPlatformKeyboardState.ThisFrameKeys[key];
}

bool rlIsPhysicalKeyUp(RLKeyboardPhysicalKey key)
{
    return !rlPlatformKeyboardState.ThisFrameKeys[key];
}

bool rlIsPhysicalKeyPressed(RLKeyboardPhysicalKey key)
{
    return rlPlatformKeyboardState.ThisFrameKeys[key] && !rlPlatformKeyboardState.LastFrameKeys[key];
}

bool rlIsPhysicalKeyReleased(RLKeyboardPhysicalKey key)
{
    return !rlPlatformKeyboardState.ThisFrameKeys[key] && rlPlatformKeyboardState.LastFrameKeys[key];
}

bool rlIsLogicalKeyDown(RLKeyboardLogicalKey key)
{
    return rlIsPhysicalKeyDown(SDL_GetScancodeFromKey(key, NULL));
}

bool rlIsLogicalKeyUp(RLKeyboardLogicalKey key)
{
    return rlIsPhysicalKeyUp(SDL_GetScancodeFromKey(key, NULL));
}

bool rlIsLogicalKeyPressed(RLKeyboardLogicalKey key)
{
    return rlIsPhysicalKeyPressed(SDL_GetScancodeFromKey(key, NULL));
}

bool rlIsLogicalKeyReleased(RLKeyboardLogicalKey key)
{
    return false;
}

uint32_t rlGetKeyDownEventListSize()
{
    return rlPlatformKeyboardState.KeyEventMapSize;
}

RLKeyboardPhysicalKey rlGetKeyDownEventListItem(uint32_t index, bool* isDown)
{
    if (isDown)
        *isDown = rlPlatformKeyboardState.KeyEventMap[index].Down;

    return rlPlatformKeyboardState.KeyEventMap[index].Key;
}

RLKeyboardLogicalKey rlGetLogicalKey(RLKeyboardPhysicalKey key)
{
    return 0;
}

RLKeyboardPhysicalKey rlGetPhysicalKey(RLKeyboardLogicalKey key)
{
    return 0;
}

const char* rlGetKeyName(RLKeyboardLogicalKey key)
{
    return SDL_GetKeyName(key);
}

bool rlIsKeyModiferDown(uint16_t modifyer)
{
    SDL_Keymod modState = SDL_GetModState();
    return (modState & modifyer) == modifyer;
}