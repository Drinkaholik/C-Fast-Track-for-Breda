#include "game.h"
#include "surface.h"

#include <cstdio> //printf
#include <iostream>
#include <cmath>
#include <algorithm>


// Source - https://stackoverflow.com/a/4609795
    // Posted by user79758, modified by community. See post 'Timeline' for change history
    // Retrieved 2026-04-16, License - CC BY-SA 4.0

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

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
  

    // Move vars
    int upMove;
    int downMove;

    int leftMove;
    int rightMove;

    int xMove;
    int yMove;

    float xVel;
    float yVel;

    float accel = 0.1;
    float decel = 0.01;
    float maxSpeed = 1;

    float xPos = 0;
    float yPos = 0;


    // -----------------------------------------------------------
    // Main application tick function
    // -----------------------------------------------------------
    void Game::Tick(float deltaTime)
    {
        
        PlayerMove();

        // clear the graphics window
        screen->Clear(0);

        tank.Draw(screen, xPos, yPos);
    }

    

    

    void Game::PlayerMove()
    {
        // Update key states
        pressed = keys & ~held; // keys that are currently down but were not down in the previous tick
        released = ~keys & held; // keys that were down in the previous tick but are not down now
        held = keys; // update prevKeys for the next tick

        upMove = (GetKey(SDL_SCANCODE_W)) ? 1 : 0;
        downMove = (GetKey(SDL_SCANCODE_S)) ? 1 : 0;
        leftMove = (GetKey(SDL_SCANCODE_A)) ? 1 : 0;
        rightMove = (GetKey(SDL_SCANCODE_D)) ? 1 : 0;
        

        xMove = rightMove - leftMove;
        yMove = upMove - downMove;


        // X-axis movement //
        if (xMove != 0) // accelerate
        {
            xVel += accel * xMove;
        }
        else // decel
        {
            xVel -= decel * sgn(xVel);

            if (std::abs(xVel) < 0.01f) // prevent overshoot
            {
                xVel = 0;
            }
        }

        // Y-axis movement //
        if (yMove != 0) // accel
        {
            yVel += accel * -yMove;

           
        }
        else // decel
        {
            yVel -= decel * sgn(yVel); 

            if (std::abs(yVel) < 0.01f) // prevent overshoot
            {
                yVel = 0;
            }
        }

        xVel = std::clamp(xVel, -maxSpeed, maxSpeed); // Clamp
        yVel = std::clamp(yVel, -maxSpeed, maxSpeed); // Clamp


        xPos += xVel;
        yPos += yVel;

        xPos = std::clamp(xPos, 0.0f, 800.0f - tank.GetWidth());
        yPos = std::clamp(yPos, 0.0f, 510.0f - tank.GetHeight());
    }




};



