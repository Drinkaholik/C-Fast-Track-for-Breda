#pragma once

#include "gameObject.h"



class Player : public GameObject
{
public:
	void Tick(); 

    // Constructor
    Player(Surface* screen, Sprite* spr, float xPos, float yPos)
        : GameObject(screen, spr, xPos, yPos)
    {
    };


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



