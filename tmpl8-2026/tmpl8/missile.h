#pragma once
#include "baseComponents.h"
#include "template.h"

class GameObject;
class ObjectPool;

class Missile : public Component
{
public:

	void Tick() override;

	void Spawn(Tmpl8::vec2 pos); // Sets angle and speed when exiting pool


	// Structors
	Missile(ObjectPool* pool, GameObject* player) : pool(pool), player(player) {};



private:

	float speed = 300.0f;
	float speedRange = 0.3f; // random range, %
	float angleRange = 0.1f;

	float lifetime = 5.0f;

	Tmpl8::vec2 direction; // Working with vector directions is soooooo nice

	GameObject* player; // Needed for targeting
	ObjectPool* pool; // Needed to return self to pool

	void SetSpeed();
	void SetDirection();

	void Move();

	void Respawn();



};

