#include "game.h"
#include "surface.h"

#include <cstdio> //printf
#include <iostream>

namespace Tmpl8
{

    int ColorArray[27]
    {
        0xff0000,
        0xff0000,
        0xff0000,
        0xff0000,
        0xff0000,
        0xff0000,
        0xff0000,
        0xff0000,
        0xff0000,
        0x00ff00,
        0x00ff00,
        0x00ff00,
        0x00ff00,
        0x00ff00,
        0x00ff00,
        0x00ff00,
        0x00ff00,
        0x00ff00,
        0x0000ff,
        0x0000ff,
        0x0000ff,
        0x0000ff,
        0x0000ff,
        0x0000ff,
        0x0000ff,
        0x0000ff,
        0x0000ff,
    };

    int loop;


    // -----------------------------------------------------------
    // Initialize the application
    // -----------------------------------------------------------
    void Game::Init()
    {
       
        for (int i = 0; i < 400; i++)
        {
            for (int j = 0; j < 400; j++)
            {
                loop++;
                if (loop > 26)
                    loop = 0;
                screen->Plot(i, j, ColorArray[loop]);
            }
            
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
        x++;
        // clear the graphics window
        //screen->Clear(0);
        // print something in the graphics window
        //screen->Print("hello world", 50+x, 50+x, 0xffffff);
        
        // print something to the text window
        // printf("this goes to the console window.\n");
        // draw a sprite
        //x++;
        //rotatingGun.SetFrame(frame);
        //rotatingGun.Draw(screen, 100 + x, 100);
        //if (++frame == 36) frame = 0;
    }

};