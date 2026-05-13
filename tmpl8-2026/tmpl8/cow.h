#pragma once

#include "baseComponents.h"
#include "template.h"



class Cow : public Component
{
public:

	void Tick() override;

	void SetScared();

	float GetRadius() { return scareRadius; };

private:

	// Speed
	float speed = 0.0f;
	float idleSpeed = 30.0f;
	float scaredSpeed = 120.0f;

	float speedRange = 0.25f; // proportional

	// Scared state
	float scaredTime = 5.0f;
	float scaredTimeRange = 0.5f;
	float counter;

	float scareRadius = 500.0f; // How close they need to be to an abduction to become scared

	Tmpl8::vec2 direction;


	void Mooooove(); // just a joke dont kill me

	void SetSpeed(float spd);

	void HandleState();

	enum CowState
	{
		Idle,
		Scared
	} cowState = CowState::Idle;



};

