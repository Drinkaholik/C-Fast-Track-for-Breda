#include "game.h"

#include "central.h"
#include "utils.h" // sign
#include "sceneManager.h"


#include <cstdio> //printf
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

namespace Tmpl8
{

    unique_ptr<SceneManager> sceneManager = make_unique<SceneManager>();


    // -----------------------------------------------------------
    // Initialize the application
    // -----------------------------------------------------------
    void Game::Init()
    {
        sceneManager->LoadScene(0, false); // Load main menu
  
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
        screen->Clear(0x008833); // clear the graphics window

        sceneManager->GetScene()->Tick(); // Drive gameObject update loop


        UpdateKeys();

        if (GetKey(SDL_SCANCODE_R))
        {
            sceneManager->LoadScene(0, false); // Load main menu
        }

        if (sceneManager->GetScene()->setReload)
            sceneManager->LoadScene(0, false);
   

    }
  
    void Game::UpdateKeys()
    {
        // Update key states
        pressed = keys & ~held; // keys that are currently down but were not down in the previous tick
        released = ~keys & held; // keys that were down in the previous tick but are not down now
        held = keys; // update prevKeys for the next tick
    };



};



