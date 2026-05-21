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
        particleSystem->Start();
    }

    void Game::Shutdown()
    {
    }




    


    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);
     
        particleSystem->DrawParticles();

    

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