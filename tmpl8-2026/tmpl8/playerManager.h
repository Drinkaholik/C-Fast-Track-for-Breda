#pragma once
#include "baseComponents.h"

class PlayerMove;
class Abductor;
class SpriteRenderer;
class PlayerHP;

class PlayerManager : public Component
{

	void Start() override;
	void Tick() override;


private:

	float evadeAccel = 2500.0f;
	float evadeDecel = 600.0f;
	float evadeMaxSpeed = 700.0f;

	float abductAccel = 500.0f;
	float abductDecel = 500.0f;
	float abductMaxSpeed = 300.0f;

	void HandleState();
	void EnterEvasive();
	void EnterAbduction();

	enum PlayerState
	{
		Abduction,
		Evasive
	} playerState = PlayerState::Abduction;


	SpriteRenderer* spriteRenderer;
	PlayerMove* playerMove;
	PlayerHP* playerHP;
	Abductor* abductor;
	

};

