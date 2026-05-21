#include "game.h"

#include "surface.h"
#include "particleSystem.h"

#include <cstdio> //printf
#include <iostream>
#include <string>

using namespace std;

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

        cout << "xPos: " << to_string(mousePos.x) << " , "
            << "yPos: " << to_string(mousePos.y) << endl;

    

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