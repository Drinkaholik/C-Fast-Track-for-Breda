#include "game.h"

#include "surface.h"
#include "particleSystem.h"

#include <cstdio> //printf
#include <iostream>


namespace Tmpl8
{

    ParticleSystem* particleSystem = new ParticleSystem();

    void Game::Init()
    {
    }

    void Game::Shutdown()
    {
    }




    


    void Game::Tick(float deltaTime)
    {
        // Update key states
        pressed = keys & ~held; // keys that are currently down but were not down in the previous tick
        released = ~keys & held; // keys that were down in the previous tick but are not down now
        held = keys; // update prevKeys for the next tick

        // clear the graphics window
        screen->Clear(0);
     

       Pixel* buffer = screen->GetBuffer();

    }


    void Game::MouseDown(int button)
    {
        particleSystem->AddParticle(mousePos.x, mousePos.y);
    }

    void Game::MouseMove(int x, int y)
    {
        mousePos.x = x;
        mousePos.y = y;
    }


};