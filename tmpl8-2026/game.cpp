#include "game.h"
#include "surface.h"
#include "utils.h" // sign
#include "gameObject.h"
#include "player.h"

#include <cstdio> //printf
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>



namespace Tmpl8
{
    // Sprites
    Sprite tank(new Surface("assets/aagun.tga"), 36);
    Sprite ball(new Surface("assets/ball.png"), 1);

    // GameObjects
    std::unique_ptr<GameObject> oPlayer;
    std::unique_ptr<GameObject> oBall;

    std::vector<std::unique_ptr<GameObject>> spawnedObjects;

    // -----------------------------------------------------------
    // Initialize the application
    // -----------------------------------------------------------
    void Game::Init()
    {

        // Instantiate gameobjects
        oPlayer = std::make_unique<Player>(screen, &tank, 0, 0);
        oBall = std::make_unique<GameObject>(screen, &ball, 200, 200);

        spawnedObjects.push_back(oPlayer);
        spawnedObjects.push_back(oBall);

        
    }

    // -----------------------------------------------------------
    // Close down application
    // -----------------------------------------------------------
    void Game::Shutdown()
    {
    }




    // -----------------------------------------------------------
    // Main application tick function
    // -----------------------------------------------------------
    void Game::Tick(float deltaTime)
    {
        screen->Clear(0); // clear the graphics window

        for (int i = 0; i < spawnedObjects.size(); i++)
        {
            spawnedObjects[i]->Tick();
        }
        

    }
  




};



