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

    vec2 rawVector = vec2(xInput, yInput);
    inputVector = vec2::normalize(rawVector);
}



void PlayerMove::Move()
{
    // X-axis movement //
    if (inputVector.x != 0) // accel
    {
        vel.x += accel * inputVector.x;
    }
    else // decel
    {
        vel.x -= decel * utils::sign(vel.x);

        if (std::abs(vel.x) < 0.01f) // prevent overshoot
            vel.x = 0;
    }

    // Y-axis movement //
    if (inputVector.y != 0) // accel
    {
        vel.y += accel * inputVector.y;
    }
    else // decel
    {
        vel.y -= decel * utils::sign(vel.y);

        if (std::abs(vel.y) < 0.01f) // prevent overshoot
            vel.y = 0;
    }

    // Clamp velocity

    float xNormMaxSpeed = abs(maxSpeed * inputVector.x); // Prevents diagonals from being faster
    float yNormMaxSpeed = abs(maxSpeed * inputVector.y);

    vel.x = std::clamp(vel.x, -xNormMaxSpeed, xNormMaxSpeed);
    vel.y = std::clamp(vel.y, -yNormMaxSpeed, yNormMaxSpeed);

    float& dt = Central::dts;

    // Update position
    gameObject->pos += vel * dt;


   /* cout << "xVel: " << to_string(normVel.x) << " , "
        << "yVel: " << to_string(normVel.y) << endl;*/

    // Not gonna use MoveAndCollide() since UFO shouldn't bump into anything
    // using vec::normalize completely ruins movement, idk why
  

};


void PlayerMove::Dash()
{
    if (!tryDash) return;

    vel += inputVector * dashSpeed;

}


