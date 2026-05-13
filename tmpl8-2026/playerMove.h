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

    // Movement values
    float accel = 0.008;
    float decel = 0.05;
    float maxSpeed = 1.2;

    Collider* collider;


    void Move();


};



