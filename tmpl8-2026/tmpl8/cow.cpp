#include "cow.h"

#include "gameObject.h"
#include "central.h"
#include "utils.h"


void Cow::Tick()
{
	HandleState();
}


void Cow::HandleState()
{

	switch (cowState)
	{ 
		case CowState::Idle :

			Mooooove();

			break;

		case CowState::Scared :

			Mooooove();
			counter -= Central::dts;

			// Transition to idle state
			if (1 == 2)
			{
				cowState = CowState::Idle;
				SetSpeed(idleSpeed * speedRange);
			}

			break;
	}
}


void Cow::Mooooove()
{
	gameObject->pos += direction * speed;
}

void Cow::SetSpeed(float spd)
{
	speed = spd;
}

void Cow::SetScared()
{
	cowState = CowState::Scared;
	SetSpeed(scaredSpeed * (1 + speedRange));
	counter = scaredTime * (1 + utils::random_range(scaredTimeRange));
}