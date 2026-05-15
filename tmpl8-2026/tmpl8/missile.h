#pragma once
#include "baseComponents.h"
#include "template.h"

class GameObject;
class ObjectPool;
class DamageSystem;

class Missile : public Component
{
public:

	void Start() override;
	void Tick() override;

	void Spawn(Tmpl8::vec2 pos); // Sets angle and speed when exiting pool


	// Structors
	Missile(Scene*, ObjectPool* pool, GameObject* player);



private:

	float speed = 900.0f;
	float speedRange = 0.3f; // random range, %
	float angleRange = 0.1f;

	float lifetime = 5.0f;
	float count;

	Tmpl8::vec2 dir; // Working with vector directions is soooooo nice

	GameObject* player; // Needed for targeting
	ObjectPool* pool; // Needed to return self to pool, injected via MissileSpawner
	DamageSystem* system; // Needed to deal damage to player
	Collider* col; // Cache


	void Move();
	void Damage();

	void SetSpeed();
	void SetDirection();
	void SetFrame();

	
	void CheckLifetime();
	void Despawn();

	



};

