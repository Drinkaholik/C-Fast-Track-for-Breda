#include "playerMove.h"

#include "utils.h"
#include "gameObject.h"

#include <cmath>
#include <algorithm>
// Console:
#include <iostream>
#include <string>

using namespace std;


PlayerMove::PlayerMove(Collider* col) : collider(col) {};

void PlayerMove::Tick()
{
    Move();
};


void PlayerMove::Move()
{

    Game& game = *Central::game; // Cache pointer as ref

    // Inputs
    game.UpdateKeys();

    int upMove = (game.GetKey(SDL_SCANCODE_W)) ? 1 : 0;
    int downMove = (game.GetKey(SDL_SCANCODE_S)) ? 1 : 0;
    int leftMove = (game.GetKey(SDL_SCANCODE_A)) ? 1 : 0;
    int rightMove = (game.GetKey(SDL_SCANCODE_D)) ? 1 : 0;

    int xInput = rightMove - leftMove;
    int yInput = upMove - downMove;


    // Handle momentum //
    // X-axis movement
    if (xInput != 0) // accel
    {
        xVel += accel * xInput;
    }
    else // decel
    {
        xVel -= decel * utils::sign(xVel);

        if (std::abs(xVel) < 0.01f) // prevent overshoot
        {
            xVel = 0;
        }
    }

    // Y-axis movement
    if (yInput != 0) // accel
    {
        yVel += accel * -yInput;
    }
    else // decel
    {
        yVel -= decel * utils::sign(yVel);

        if (std::abs(yVel) < 0.01f) // prevent overshoot
        {
            yVel = 0;
        }
    }

    // Clamp velocity
    xVel = std::clamp(xVel, -maxSpeed, maxSpeed); 
    yVel = std::clamp(yVel, -maxSpeed, maxSpeed); 

    // Update position
    float& xPos = gameObject->x;
    float& yPos = gameObject->y;

    float& dt = Central::deltaTime;

    collider->MoveAndCollide(xVel * dt, yVel * dt, Central::spawnedObjects);


    // Position clamp doesnt work with component setup, since it relies on width/height values that might not exist
    // Ig thats the responsibility of the collider. 
   /* xPos = clamp(xPos, (float)width/2, (float)Central::screenWidth - width/2);
    yPos = clamp(yPos, (float)height/2, (float)Central::screenHeight - height/2);*/


};


