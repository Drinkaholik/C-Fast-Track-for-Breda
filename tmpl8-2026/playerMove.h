#pragma once

#include "baseComponents.h"
#include "template.h"


class PlayerMove : public Component
{
public:

	void Tick() override; 

    // Structors
    PlayerMove(Collider* col) : collider(col) {};


private:

    // Track current velocity
    Tmpl8::vec2 vel = Tmpl8::vec2(0, 0);

    // Base movement
    float accel = 900;
    float decel = 400;
    float maxSpeed = 600;

    // Dash
    float dashSpeed = 300;
    bool tryDash = false;

    Tmpl8::vec2 inputVector = Tmpl8::vec2(0, 0);

    Collider* collider;

    void UpdateInputs();

    void Move();

    void Dash();


};



