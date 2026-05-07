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

	GravBody(int m, Collider* collider);

private:

	Collider* collider;

	void Gravity(GameObject& body);


};

