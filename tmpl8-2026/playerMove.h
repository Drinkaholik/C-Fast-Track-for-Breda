#pragma once

#include "baseComponents.h"



class PlayerMove : public Component
{
public:

	void Tick() override; 

    PlayerMove(Collider* col);


private:

    // Track current velocity
    float xVel = 0;
    float yVel = 0;

    // Movement values
    float accel = 0.01;
    float decel = 0.001;
    float maxSpeed = 1;

    Collider* collider;


    void Move();


};



