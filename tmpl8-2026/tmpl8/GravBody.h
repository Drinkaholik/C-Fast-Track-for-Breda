#pragma once
#include "baseComponents.h"
#include "template.h"


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

	GravBody(float m, Tmpl8::vec2 vel, Collider* collider);

private:

	Tmpl8::vec2 vel = Tmpl8::vec2(0, 0);

	static float gravConstant;

	Collider* collider;

	void GravMove(GravBody* body);

};

