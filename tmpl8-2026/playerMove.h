#pragma once

#include "baseComponents.h"



class Move : public Component
{
public:
	void Tick() override; 

    Move(Collider* col);


private:

    // Track current velocity
    float xVel = 0;
    float yVel = 0;

    // Movement values
    float accel = 0.01;
    float decel = 0.001;
    float maxSpeed = 2;

    Collider* collider;


    void Move();


};



