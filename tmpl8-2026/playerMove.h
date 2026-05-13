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
    float accel = 60;
    float decel = 30;
    float maxSpeed = 180;

    Collider* collider;


    void Move();


};



