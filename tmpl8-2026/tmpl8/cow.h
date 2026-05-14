#pragma once

#include "baseComponents.h"
#include "template.h"

class ObjectPool;

class Cow : public Component
{
public:

	void Start() override;
	void Tick() override;

	void SetScared(float scareAmount); // scareAmount determined by proximity to scare sources

	float GetRadius() { return scareRadius; };

	// Structors
	Cow(ObjectPool* pool) : pool(pool) {};

private:

	
	// Idle state
	float idleDuration = 5.0f;
	float idleDurationRange = 0.75f;


	// Walk state
	float walkSpeed = 30.0f;
	float walkSpeedRange = 0.25f; // proportional, for randomization
	float walkDuration = 5.0f;
	float walkDurationRange = 0.5f;

	// Scared state
	float scaredSpeed = 120.0f;
	float scaredDuration = 5.0f;
	float minScare = 0.5f;
	float maxScare = 1.5f;
	float scaredLevel; // Defines speed and duration
	float counter;

	float scareRadius = 500.0f; // How close they need to be to an abduction to become scared
	float scareRadiusRange = 0.5f;



	Tmpl8::vec2 moveDir;
	float speed;


	void Mooooove(); // Exceptionally cow-like movement

	void SetDir();
	void SetSpeed(float spd);

	void SetIdle();
	void SetWalking();

	void HandleState();

	enum CowState
	{
		Idle,
		Walking,
		Scared
	} cowState = CowState::Idle;


	ObjectPool* pool; // to return self to pool, injected via CowManager

};

