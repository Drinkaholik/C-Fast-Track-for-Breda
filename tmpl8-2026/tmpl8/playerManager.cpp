#include "playerManager.h"

#include "central.h"
#include "playerMove.h"
#include "abductor.h"
#include "gameObject.h"
#include "playerHP.h"


void PlayerManager::Start()
{
	spriteRenderer = gameObject->GetComponent<SpriteRenderer>();
	abductor = gameObject->GetComponent<Abductor>();
	playerMove = gameObject->GetComponent<PlayerMove>();
	playerHP = gameObject->GetComponent<PlayerHP>();


	EnterAbduction();
}



void PlayerManager::Tick()
{

	Central::game->UpdateKeys();
	HandleState();
}



void PlayerManager::HandleState()
{
	switch (playerState)
	{
	case PlayerState::Abduction:

		if (Central::game->GetKeyPressed(SDL_SCANCODE_SPACE))
		{
			EnterEvasive();
		}
		break;


	case PlayerState::Evasive:

		if (Central::game->GetKeyPressed(SDL_SCANCODE_SPACE))
		{
			EnterAbduction();
		}
		break;
	}
}




void PlayerManager::EnterEvasive()
{
	playerMove->SetStats(evadeAccel, evadeDecel, evadeMaxSpeed);
	abductor->CanAbduct(false);
	spriteRenderer->SetSprite("ufo_green");
	spriteRenderer->SetFrame(playerHP->GetHP() - 1);

	playerState = PlayerState::Evasive;

}

void PlayerManager::EnterAbduction()
{
	playerMove->SetStats(abductAccel, abductDecel, abductMaxSpeed);
	abductor->CanAbduct(true);
	spriteRenderer->SetSprite("ufo");
	spriteRenderer->SetFrame(playerHP->GetHP() - 1);

	playerState = PlayerState::Abduction;

}