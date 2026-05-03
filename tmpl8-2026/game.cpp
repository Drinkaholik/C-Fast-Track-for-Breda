#include "game.h"

#include "central.h"
//#include "surface.h"
#include "utils.h" // sign
#include "gameObject.h"
#include "player.h"


#include <cstdio> //printf
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

namespace Tmpl8
{
    // Sprites
    Sprite tank(new Surface("assets/aagun.tga"), 36);
    Sprite ball(new Surface("assets/ball.png"), 1);


    // GameObjects
    shared_ptr<GameObject> oPlayer;
    shared_ptr<GameObject> oBall;

    vector<shared_ptr<GameObject>> spawnedObjects;

    vector<int> exampleVector (5, 20);

    // -----------------------------------------------------------
    // Initialize the application
    // -----------------------------------------------------------
    void Game::Init()
    {

        // Instantiate gameobjects
        oPlayer = make_shared<GameObject>(0.0f, 0.0f);
        oPlayer->AddComponent<SpriteRenderer>(&tank);
        oPlayer->AddComponent<Player>();

        oBall = make_shared<GameObject>(200.0f, 200.0f);

        spawnedObjects.push_back(oPlayer);
        spawnedObjects.push_back(oBall);

        
    }

    // -----------------------------------------------------------
    // Close down application
    // -----------------------------------------------------------
    void Game::Shutdown() // when do i actually need this? filesaving?
    {
    }




    // -----------------------------------------------------------
    // Main application tick function
    // -----------------------------------------------------------
    void Game::Tick(float deltaTime)
    {
        screen->Clear(0); // clear the graphics window

       
        for (shared_ptr<GameObject> go : spawnedObjects)
        {
            go->Tick();
        }
        
        ShowFPS(10, 10, deltaTime);

        screen->Bar(100, 100, 300, 120, 0xFFFFFF);

        screen->Plot(300, 300, 0xFF0000);

    }
  
    void Game::UpdateKeys()
    {
        // Update key states
        pressed = keys & ~held; // keys that are currently down but were not down in the previous tick
        released = ~keys & held; // keys that were down in the previous tick but are not down now
        held = keys; // update prevKeys for the next tick
    };

    float smoothedFPS = 1;
    float smoothing = 400; // Higher means smoother FPS, but less precise

    void Game::ShowFPS(int xPos, int yPos, float deltaTime)
    {

        // Why mult by 1000 specifically? Measured in milliseconds?
        // Idk but it matches what i can see with sprite movement
        float realFPS = (1 / deltaTime) * 1000; 

        // Higher value as the gap between realFPS and smoothedFPS increases,
        // stops it from taking ages to catch up
        float dynamicSmoothing = abs(1 - (realFPS / smoothedFPS)) / smoothing;

        smoothedFPS = lerp(smoothedFPS, realFPS, dynamicSmoothing);


        screen->Print(to_string(smoothedFPS).c_str(), xPos, yPos, 0xFFFFFF);
    }

    



};



