#include "player.h"

#include "locator.h"
#include "utils.h"
#include "game.h"

#include <cmath>
#include <algorithm>


void Player::Tick()
{
    GameObject::Tick();
    PlayerMove();
   

};


void Player::PlayerMove()
{

    int upMove = (Locator::g->GetKey(SDL_SCANCODE_W)) ? 1 : 0;
    int downMove = (Locator::g->GetKey(SDL_SCANCODE_S)) ? 1 : 0;
    int leftMove = (Locator::g->GetKey(SDL_SCANCODE_A)) ? 1 : 0;
    int rightMove = (Locator::g->GetKey(SDL_SCANCODE_D)) ? 1 : 0;


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

    xVel = std::clamp(xVel, -maxSpeed, maxSpeed); // Clamp
    yVel = std::clamp(yVel, -maxSpeed, maxSpeed); // Clamp

    float* xPos = &GameObject::transform.x;
    float* yPos = &GameObject::transform.y;

    *xPos += xVel;
    *yPos += yVel;

    *xPos = std::clamp(*xPos, 0.0f, 800.0f - GameObject::sprite->GetWidth());
    *yPos = std::clamp(*yPos, 0.0f, 510.0f - GameObject::sprite->GetHeight());


};


