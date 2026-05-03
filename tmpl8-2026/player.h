#pragma once

#include "baseComponents.h"



class Player : public Component
{
public:
	void Tick() override; 


private:

    // Track current velocity
    float xVel = 0;
    float yVel = 0;

    // Movement values
    float accel = 0.1;
    float decel = 0.01;
    float maxSpeed = 1;


    void PlayerMove();


};



