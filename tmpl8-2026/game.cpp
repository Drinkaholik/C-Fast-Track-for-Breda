#include "game.h"
#include "surface.h"

#include <cstdio> //printf
#include <iostream>

namespace Tmpl8
{

    struct Line
    {
        int x1;
        int y1;
        int x2;
        int y2;
        int colour;
    };

    Line lines[13];


    // -----------------------------------------------------------
    // Initialize the application
    // -----------------------------------------------------------
    void Game::Init()
    {
        // Letter C
        lines[0] = { 80, 180, 0, 240, 0xff0000 };
        lines[1] = { 0, 240, 80, 300, 0xff0000 };

        // Letter 0
        lines[2] = { 240, 180, 160, 180, 0x00ff00 };
        lines[3] = { 160, 180, 160, 300, 0x00ff00 };
        lines[4] = { 160, 300, 240, 300, 0x00ff00 };
        lines[5] = { 240, 300, 240, 180, 0x00ff00 };

        // Letter D
        lines[6] = { 320, 180, 320, 300, 0x0000ff };
        lines[7] = { 320, 300, 400, 240, 0x0000ff };
        lines[8] = { 400, 240, 320, 180, 0x0000ff };

        // Letter E
        lines[9] = { 480, 180, 480, 300, 0xffff00 };
        lines[10] = { 480, 180, 560, 180, 0xffff00 };
        lines[11] = { 480, 240, 560, 240, 0xffff00 };
        lines[12] = { 480, 300, 560, 300, 0xffff00 };


        /*for (int i = 0; i < 13; i++)
        {
            screen->Line(lines[i].x1, lines[i].y1, lines[i].x2, lines[i].y2, lines[i].colour);
        }*/

        // More syntactically concise for loop
        for (Line i : lines)
        {
            screen->Line(i.x1, i.y1, i.x2, i.y2, i.colour);
        }

        



    }

    // -----------------------------------------------------------
    // Close down application
    // -----------------------------------------------------------
    void Game::Shutdown()
    {
    }

    static Sprite rotatingGun(new Surface("assets/aagun.tga"), 36);
    static int frame = 0;
    int x = 0;

    // -----------------------------------------------------------
    // Main application tick function
    // -----------------------------------------------------------
    void Game::Tick(float deltaTime)
    {
        // Update key states
        pressed = keys & ~held; // keys that are currently down but were not down in the previous tick
        released = ~keys & held; // keys that were down in the previous tick but are not down now
        held = keys; // update prevKeys for the next tick

        // Handle input.
        if (GetKey(SDL_SCANCODE_W))
        {
            std::cout << "W" << std::endl;
        }
        if (GetKey(SDL_SCANCODE_A))
        {
            std::cout << "A" << std::endl;
        }
        if (GetKey(SDL_SCANCODE_S))
        {
            std::cout << "S" << std::endl;
        }
        if (GetKey(SDL_SCANCODE_D))
        {
            std::cout << "D" << std::endl;
        }

        // clear the graphics window
        //screen->Clear(0);
        // print something in the graphics window
        //screen->Print("hello world", 50, 50, 0xffffff);
        // print something to the text window
        // printf("this goes to the console window.\n");
        // draw a sprite
        //x++;
        //rotatingGun.SetFrame(frame);
        //rotatingGun.Draw(screen, 100 + x, 100);
        //if (++frame == 36) frame = 0;
    }

};