#include "reylib_input_keyboard.h"

#include "platforms/reylib_platform.h"

RLPlaformKeyboardState rlPlatformKeyboardState;

void sdlProcessKeyEvents(SDL_Event* event)
{

}

void sdlUpdateKeyboardFrame()
{
    for (uint16_t i = 0; i < RLPK_MAX; i++)
    {

    }
}

bool rlIsPhysicalKeyDown(RLKeyboardPhysicalKey key)
{
    return false;
}

bool rlIsPhysicalKeyUp(RLKeyboardPhysicalKey key)
{
    return false;
}
bool rlIsPhysicalKeyPressed(RLKeyboardPhysicalKey key)
{
    return false;
}
bool rlIsPhysicalKeyReleased(RLKeyboardPhysicalKey key)
{
    return false;
}

bool rlIsLogicalKeyDown(RLKeyboardLogicalKey key)
{
    return false;
}
bool rlIsLogicalKeyUp(RLKeyboardLogicalKey key)
{
    return false;
}
bool rlIsLogicalKeyPressed(RLKeyboardLogicalKey key)
{
    return false;
}
bool rlIsLogicalKeyReleased(RLKeyboardLogicalKey key)
{
    return false;
}

uint32_t rlGetKeyDownEventListSize()
{
    return 0;
}

RLKeyboardPhysicalKey rlGetKeyDownEventListItem(uint32_t index)
{
    return 0;
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
    return NULL;
}

bool rlIsKeyModiferDown(uint16_t modifyer)
{
    return false;
}