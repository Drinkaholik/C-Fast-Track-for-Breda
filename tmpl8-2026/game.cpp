#include "game.h"
#include "surface.h"

#include <cstdio> //printf
#include <iostream>
#include <cmath>

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

    Sprite tank(new Surface("assets/aagun.tga"), 36);
  

    // -----------------------------------------------------------
    // Main application tick function
    // -----------------------------------------------------------
    void Game::Tick(float deltaTime)
    {
        
        PlayerMove();

        // clear the graphics window
        screen->Clear(0);

        screen->Sprite::Draw(tank, xPos, yPos);


        
    }

    int upMove;
    int downMove;

    int leftMove;
    int rightMove;

    int xMove;
    int yMove;

    float xAccel;
    float yAccel;

    float accel = 0.5;
    float maxSpeed = 2;

    int xPos = 0;
    int yPos = 0;
    

    void Game::PlayerMove()
    {
        // Update key states
        pressed = keys & ~held; // keys that are currently down but were not down in the previous tick
        released = ~keys & held; // keys that were down in the previous tick but are not down now
        held = keys; // update prevKeys for the next tick

        upMove = (GetKey(SDL_SCANCODE_W)) ? 1 : 0;
        downMove = (GetKey(SDL_SCANCODE_A)) ? 1 : 0;
        leftMove = (GetKey(SDL_SCANCODE_S)) ? 1 : 0;
        rightMove = (GetKey(SDL_SCANCODE_D)) ? 1 : 0;
        

        xMove = rightMove - leftMove;
        yMove = upMove - downMove;


        if (std::abs(xAccel) > maxSpeed)
        {
            xAccel += accel * xMove;
        };

        if (std::abs(yAccel) > maxSpeed)
        {
            yAccel += accel * yMove;
        };

        xPos += xAccel;
        yPos += yAccel;
    }




};