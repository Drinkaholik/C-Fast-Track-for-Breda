#include "game.h"

#include "central.h"
#include "utils.h" // sign
#include "gameObject.h"
#include "playerMove.h"
#include "gravBody.h"


#include <cstdio> //printf
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

namespace Tmpl8
{
    // Sprites
    Sprite sTank(new Surface("assets/aagun.tga"), 36);
    Sprite sBall(new Surface("assets/ball.png"), 1);
    Sprite sBall2(new Surface("assets/ball.png"), 1);

    // GameObjects
    shared_ptr<GameObject> oPlayer;
    shared_ptr<GameObject> oBall;
    shared_ptr<GameObject> oBall2;

    vector<int> exampleVector (5, 20);

    // -----------------------------------------------------------
    // Initialize the application
    // -----------------------------------------------------------
    void Game::Init()
    {

        // Player
        oPlayer = make_shared<GameObject>(0.0f, 0.0f, true);
        oPlayer->AddComponent<SpriteRenderer>(&sTank);
        oPlayer->AddComponent<Collider>(&sTank);
        oPlayer->AddComponent<PlayerMove>(oPlayer->GetComponent<Collider>());

       /* bool test = oPlayer->RemoveComponent<SpriteRenderer>();
        cout << to_string(test);*/
        
        int scrWidth = Central::screenWidth;
        int scrHeight = Central::screenHeight;


        oBall = make_shared<GameObject>(scrWidth * 0.75, scrHeight * 0.45, true);
        oBall->AddComponent<SpriteRenderer>(&sBall);
        oBall->AddComponent<Collider>(&sBall);
        oBall->AddComponent<GravBody>(1.0f, 0.0f, -1.0f, oBall->GetComponent<Collider>());

        oBall2 = make_shared<GameObject>(scrWidth * 0.25, scrHeight * 0.55, true);
        oBall2->AddComponent<SpriteRenderer>(&sBall2);
        oBall2->AddComponent<Collider>(&sBall2);
        oBall2->AddComponent<GravBody>(1.0f, 0.0f, 1.0f, oBall2->GetComponent<Collider>());

        // Render order is determined by the order they're pushed
        Central::spawnedObjects.push_back(oBall);
        Central::spawnedObjects.push_back(oBall2);
        Central::spawnedObjects.push_back(oPlayer);
        
        Central::gravBodies.push_back(oBall);
        Central::gravBodies.push_back(oBall2);
        

        
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

        // Drive gameObject update loop
        for (shared_ptr<GameObject> go : Central::spawnedObjects)
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
    float smoothing = 100; // Higher means smoother FPS, but less precise

    void Game::ShowFPS(int xPos, int yPos, float deltaTime)
    {

        // Why mult by 1000 specifically? Measured in milliseconds?
        // Idk but it matches what i can see with sprite movement
        float realFPS = (1 / deltaTime) * 1000; 

        // Higher value as the gap between realFPS and smoothedFPS increases,
        // stops it from taking ages to catch up
        float dynamicSmoothing = (abs(1 - realFPS / smoothedFPS)) / smoothing;

        smoothedFPS = lerp(smoothedFPS, realFPS, dynamicSmoothing);


        screen->Print(to_string(smoothedFPS).c_str(), xPos, yPos, 0xFFFFFF);
    }

    



};



