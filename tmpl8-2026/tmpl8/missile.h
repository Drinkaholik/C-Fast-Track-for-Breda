#pragma once
#include "baseComponents.h"
#include "template.h"

class GameObject;


class Missile : public Component
{
public:

	void Tick() override;

	void Spawn(Tmpl8::vec2 pos); // Sets angle and speed when exiting pool


	// Structors
	Missile(GameObject* player) : player(player) {};



private:

	float speed = 5;
	float speedRange = 2; // random range
	float angleRange = 0.1;

	Tmpl8::vec2 direction; // Working with vector directions is soooooo nice

	GameObject* player;

	void SetSpeed();
	void SetDirection();

	void Move();



};

