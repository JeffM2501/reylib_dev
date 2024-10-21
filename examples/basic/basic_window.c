// basic_window.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "reylib.h"

RLPoint2F Position = { 0 };

bool Init(void)
{
    Position = (RLPoint2F){ 100,100 };
    return false;
}

bool Update(void)
{
    if (rlWantExit())
        return true;

    Position.X += 100 * rlGetFrameTime();

    return false;
}

bool Render(void)
{
    rlClearBackgroud(DARKBLUE);

    rlDrawRectangleAtPosition(Position, (RLRectangle2F){ 0, 0, 32, 32 }, RED);
    return false;
}

bool Shutdown(void)
{
    return false;
}

int main()
{
    bool useCallbacks = true;

    if (useCallbacks)
    {
        rlInitApp(800, 600, "TestWindow", 0, Update, Render, Init, Shutdown);
    }
    else
    {
        rlInitAppSimple(800, 600, "TestWindow-loop", 0);
        Init();
        while (!rlWantExit())
        {
            rlBeginFrame();

            if (!Update() || !Render())
                break;

            rlEndFrame();
        }
        Shutdown();

        rlShutdown();
    }
}
