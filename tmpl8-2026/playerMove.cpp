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
        vel.x += accel * xInput;
    }
    else // decel
    {
        vel.x -= decel * utils::sign(vel.x);

        if (std::abs(vel.x) < 0.01f) // prevent overshoot
        {
            vel.x = 0;
        }
    }

    // Y-axis movement
    if (yInput != 0) // accel
    {
        vel.y += accel * -yInput;
    }
    else // decel
    {
        vel.y -= decel * utils::sign(vel.y);

        if (std::abs(vel.y) < 0.01f) // prevent overshoot
        {
            vel.y = 0;
        }
    }

    // Clamp velocity
    vel.x = std::clamp(vel.x, -maxSpeed, maxSpeed); 
    vel.y = std::clamp(vel.y, -maxSpeed, maxSpeed); 

    // Update position
    float& xPos = gameObject->pos.x;
    float& yPos = gameObject->pos.y;

    float& dt = Central::deltaTime;

    vec2 normVel = vec2::normalize(vel);

    cout << "xVel: " << to_string(normVel.x)
        << "yVel: " << to_string(normVel.y) << endl;

    // Not gonna use MoveAndCollide() since UFO shouldn't bump into anything
    xPos += vel.x;
    yPos += vel.y;

};


