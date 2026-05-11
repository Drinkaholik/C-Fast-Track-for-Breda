#include "game.h"
#include "surface.h"

#include <cstdio> //printf
#include <iostream>

namespace Tmpl8
{
    // -----------------------------------------------------------
    // Initialize the application
    // -----------------------------------------------------------
    void Game::Init()
    {
    }

    // -----------------------------------------------------------
    // Close down application
    // -----------------------------------------------------------
    void Game::Shutdown()
    {
    }

    Surface image("assets/ball.png");

    // -----------------------------------------------------------
    // Main application tick function
    // -----------------------------------------------------------
    void Game::Tick(float deltaTime)
    {
        // clear the graphics window
        screen->Clear(0);
        // draw a grid
        Pixel* buffer = screen->GetBuffer();

        int gridSize = 8;
        int colour = 50000;

        for (int x = 0; x < 800 / gridSize; x++)
        {
            buffer[x * gridSize] = colour;
            for (int y = 0; y < 5012 / gridSize; y++)
            {
           
                buffer[y * x * gridSize] = colour;
            }
        }

    }
};