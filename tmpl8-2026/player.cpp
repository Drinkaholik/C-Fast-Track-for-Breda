#include "player.h"

#include "central.h"
#include "utils.h"
#include "game.h"

#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>


void Player::Tick()
{
    GameObject::Tick();
    PlayerMove();
};


void Player::PlayerMove()
{

    // Update key states
    Central::game->UpdateKeys();

    int upMove = (Central::game->GetKey(SDL_SCANCODE_W)) ? 1 : 0;
    int downMove = (Central::game->GetKey(SDL_SCANCODE_S)) ? 1 : 0;
    int leftMove = (Central::game->GetKey(SDL_SCANCODE_A)) ? 1 : 0;
    int rightMove = (Central::game->GetKey(SDL_SCANCODE_D)) ? 1 : 0;


    int xInput = rightMove - leftMove;
    int yInput = upMove - downMove;

    // X-axis movement //
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

    // Y-axis movement //
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
    float& xPos = GameObject::x;
    float& yPos = GameObject::y;

    float& dt = Central::deltaTime;

    xPos += xVel * dt;
    yPos += yVel * dt;

    std::cout << std::to_string(dt) << std::endl;

    xPos = std::clamp(xPos, (float)width/2, (float)Central::screenWidth - width/2);
    yPos = std::clamp(yPos, (float)height/2, (float)Central::screenHeight - height/2);


};


