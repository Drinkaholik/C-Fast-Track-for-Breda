#pragma once
#include "baseComponents.h"


class GravBody : public Component
{

	/*Whats the best way to do this ?
	Should they all be circle colliders?
	Would make most sense for planets
	But idk how to mix AABB and circle colliders*/

public:
	float mass;

	void Tick() override;

	GravBody(float m, Collider* collider);

	GravBody(float m, float xVel, float yVel, Collider* collider);

private:

	float xVel, yVel = 0.0f;

	Collider* collider;

	void GravMove(GameObject* body);

};

