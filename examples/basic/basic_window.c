// basic_window.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "reylib.h"

RLPoint2F Position = { 0 };

RLImage Image = { 0 };
RLTexture Texture = { 0 };
RLTexture Parots = { 0 };

bool Init(void)
{
    Position = (RLPoint2F){ 100,100 };

    Image = rlLoadImageFile("../../../../examples/basic/resources/test.png");
    Texture = rlLoadTextureFromImage(Image);
    rlDestoryImage(Image);

    Parots = rlLoadTexture("../../../../examples/basic/resources/parrots.png");

    return false;
}

bool Update(void)
{
    if (rlWantExit())
        return true;

    float speed = 100;

    if (rlIsPhysicalKeyDown(RLPK_W))
        Position.Y -= speed * rlGetFrameTime();

    if (rlIsPhysicalKeyDown(RLPK_S))
        Position.Y += speed * rlGetFrameTime();

    if (rlIsPhysicalKeyDown(RLPK_D))
        Position.X += speed * rlGetFrameTime();

    if (rlIsPhysicalKeyDown(RLPK_A))
        Position.X -= speed * rlGetFrameTime();

    return false;
}

bool Render(void)
{
    rlClearBackgroud(DARKBLUE);

    rlDrawTexture(Parots, (RLRectangle2F){ 150, 150, rlGetWindowSize().X - 150, rlGetWindowSize().Y - 150 }, WHITE);

    rlDrawRectangleAtPosition((RLRectangle2F){ -16, -16, 32, 32 }, Position , RED);

    rlDrawTextureAtPosition(Texture, RLPoint2FZeros, WHITE);

    return false;
}

bool Shutdown(void)
{
    rlDestoryTexture(Parots);
    rlDestoryTexture(Texture);
    return false;
}

int main()
{
    bool useCallbacks = true;

    if (useCallbacks)
    {
        rlInitApp(800, 600, "ReyLib TestWindow", 0, Update, Render, Init, Shutdown);
    }
    else
    {
        rlInitAppSimple(800, 600, "ReyLib TestWindow-loop", 0);
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
