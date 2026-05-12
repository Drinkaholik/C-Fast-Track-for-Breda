#include "game.h"
#include "surface.h"
#include "template.h"

#include <cstdio> //printf
#include <iostream>

namespace Tmpl8
{
    // -----------------------------------------------------------
    // Initialize the application
    // -----------------------------------------------------------
    int x[4096], y[4096];

    void Game::Init()
    {
        for (int i = 0; i < 4096; i++)
            x[i] = IRand(800), y[i] = IRand(512);
    }

    void Game::Shutdown() {}

    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);
        for (int i = 0; i < 4096; i++)
        {
            x[i] = (x[i] + 800 + (((i & 1) * 2) - 1)) % 800;
            y[i] = (y[i] + 512 + ((((i >> 2) & 1) * 2) - 1)) & 511;
            screen->GetBuffer()[x[i] + y[i] * 800] = 0xffffff;
        }
    }
};