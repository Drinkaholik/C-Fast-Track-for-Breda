#include "game.h"

#include "central.h"
#include "utils.h" // sign
#include "gameObject.h"
#include "playerMove.h"
#include "gravBody.h"
#include "camera.h"
#include "sceneManager.h"


#include <cstdio> //printf
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

namespace Tmpl8
{
    SceneManager* sceneManager = new SceneManager();

    // Camera
    shared_ptr<GameObject> oCamera;
    int scrWidth = Central::screenWidth;
    int scrHeight = Central::screenHeight;


    // -----------------------------------------------------------
    // Initialize the application
    // -----------------------------------------------------------
    void Game::Init()
    {

        // Camera
        oCamera = make_shared<GameObject>(400.0f, 400.0f);
        oCamera->AddComponent<Camera>(nullptr);


        oCamera->GetComponent<Camera>()->SetTarget(oPlayer.get());
        
        // Execution & render order is determined by the order they're pushed
        // Later objects are rendered on top
        
        // Vector of gravitational bodies
        
        // Run Start() for every gameObject
        for (shared_ptr<GameObject> go : Central::spawnedObjects)
        {
            go->Start();
        }
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


    void Game::MouseMove(int x, int y)
    {

    }



    // FPS counter //
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



