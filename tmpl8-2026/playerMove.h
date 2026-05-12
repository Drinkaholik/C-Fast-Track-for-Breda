#pragma once

#include "baseComponents.h"
#include "template.h"


class PlayerMove : public Component
{
public:

	void Tick() override; 

    PlayerMove(Collider* col);


private:

    // Track current velocity
    Tmpl8::vec2 vel = Tmpl8::vec2(0, 0);

    // Movement values
    float accel = 0.1;
    float decel = 0.001;
    float maxSpeed = 2;

    Collider* collider;


    void Move();


};



