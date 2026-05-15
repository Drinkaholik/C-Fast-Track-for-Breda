#include "playerMove.h"

#include "utils.h"
#include "gameObject.h"

#include <cmath>
#include <algorithm>
// Console:
#include <iostream>
#include <string>

using namespace std;
using namespace Tmpl8;

void PlayerMove::Tick()
{
    UpdateInputs();
    Move();
    Dash();
};

void PlayerMove::UpdateInputs()
{
    Game& game = *Central::game; // Get ref to game

    // Inputs
    game.UpdateKeys();

    int upMove = (game.GetKey(SDL_SCANCODE_W)) ? 1 : 0;
    int downMove = (game.GetKey(SDL_SCANCODE_S)) ? 1 : 0;
    int leftMove = (game.GetKey(SDL_SCANCODE_A)) ? 1 : 0;
    int rightMove = (game.GetKey(SDL_SCANCODE_D)) ? 1 : 0;

    bool tryDash = (game.GetKey(SDL_SCANCODE_LSHIFT)) ? 1 : 0;

    int xInput = rightMove - leftMove;
    int yInput = downMove - upMove;

    vec2 rawVector = vec2((float)xInput, (float)yInput);
    inputVector = vec2::normalize(rawVector);

   /* cout << "inputvector - " << "x: " << to_string(inputVector.x) << " , "
        << "y: " << to_string(inputVector.y) << endl;*/
}



void PlayerMove::Move()
{
    float& dt = Central::dts;

    // X-axis movement //
    if (abs(inputVector.x) > 0.01f) // accel
    {
        vel.x += accel * inputVector.x * dt;
    }
    else // decel
    {
        vel.x -= decel * utils::sign(vel.x) * dt;

        if (std::abs(vel.x) < 0.01f) // prevent overshoot
            vel.x = 0;
    }

    // Y-axis movement //
    if (abs(inputVector.y) > 0.01f) // accel
    {
        vel.y += accel * inputVector.y * dt;
    }
    else // decel
    {
        vel.y -= decel * utils::sign(vel.y) * dt;

        if (std::abs(vel.y) < 0.01f) // prevent overshoot
            vel.y = 0;
    }

    // Clamp velocity //
    // Bit of a scuffed way to handle this but hey it works
    float xClamp = 0;
    float yClamp = 0;

    if (inputVector.length() > 1)
    {
        xClamp = abs(maxSpeed * inputVector.x); // Prevents diagonals from being faster
        yClamp = abs(maxSpeed * inputVector.y);
    }
    else
    {
        xClamp = maxSpeed; 
        yClamp = maxSpeed;
    }
    
    vel.x = std::clamp(vel.x, -xClamp, xClamp);
    vel.y = std::clamp(vel.y, -yClamp, yClamp);


    // Update position //
    gameObject->pos += vel * dt;

    /*cout << "xVel: " << to_string(vel.x) << " , "
        << "yVel: " << to_string(vel.y) << endl;*/
};


void PlayerMove::Dash()
{
    if (!tryDash) return;

    vel += inputVector * dashSpeed;

}


