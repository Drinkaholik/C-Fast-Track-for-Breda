#pragma once

#include "baseComponents.h"
#include "template.h"


class PlayerMove : public Component
{
public:

	void Tick() override; 

    void SetStats(float accel, float decel, float maxSpeed);

    // Structors
    PlayerMove(Collider* col) : collider(col) {};


private:

    // Track current velocity
    Tmpl8::vec2 vel = Tmpl8::vec2(0, 0);

    // Base movement
    float accel = 0.0f;
    float decel = 0.0f;
    float maxSpeed = 0.0f;

    Tmpl8::vec2 inputVector = Tmpl8::vec2(0, 0);

    Collider* collider;

    void UpdateInputs();

    void Move();






