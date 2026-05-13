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
    float accel = 60;
    float decel = 30;
    float maxSpeed = 180;

    // Dash
    float dashSpeed = 300;
    bool tryDash;

    Tmpl8::vec2 inputVector = Tmpl8::vec2(0, 0);

    Collider* collider;

    void UpdateInputs();

    void Move();

    void Dash();


};



