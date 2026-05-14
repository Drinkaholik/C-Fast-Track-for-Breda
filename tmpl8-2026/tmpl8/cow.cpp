#include "cow.h"

#include "gameObject.h"
#include "central.h"
#include "utils.h"

#include <iostream>
#include <string>

using namespace Tmpl8;
using namespace std;

void Cow::Start()
{
	SetDir();
	SetSpeed(walkSpeed * (1 + utils::random_range(walkSpeedRange)));

	scareRadius = baseScareRadius * (1 + utils::random_range(scareRadiusRange));

	/*cout << "dir - " << "x: " << to_string(moveDir.x) << " , " << "y: " << to_string(moveDir.y) << " , " << endl
		<< "speed: " << to_string(speed) << endl;*/
}

void Cow::Tick()
{
	HandleState();
}


void Cow::HandleState()
{
	switch (cowState)
	{
	case CowState::Idle:
		
		counter -= Central::dts;
		if (counter <= 0) SetWalking();

		break;


	case CowState::Walking:
		
		Mooooove();

		counter -= Central::dts;
		if (counter <= 0)
		{
			if (utils::flip()) SetIdle();
			else SetWalking(); // Randomizes moveDir and speed
		}
		
		break;


	case CowState::Scared:

		Mooooove();

		counter -= Central::dts;
		if (counter <= 0)
		{
			if (utils::flip()) SetIdle();
			else SetWalking();
		}

		break;
	}
}

void Cow::SetIdle()
{
	cowState = CowState::Idle;
	counter = idleDuration * (1 + utils::random_range(idleDurationRange));
}

void Cow::SetWalking()
{
	cowState = CowState::Walking;
	counter = walkDuration * (1 + utils::random_range(walkDurationRange));

	SetDir();
	SetSpeed(walkSpeed * (1 + utils::random_range(walkSpeedRange)));
}

void Cow::SetScared(float amount)
{
	if (cowState == CowState::Scared) return;
	amount = Clamp(amount, minScare, maxScare);

	cowState = CowState::Scared;
	counter = scaredDuration * amount;

	SetDir();
	SetSpeed(scaredSpeed * amount);
}




void Cow::Mooooove()
{
	gameObject->pos += moveDir * speed * Central::dts;
}

void Cow::SetDir()
{
	moveDir = vec2::normalize(
		vec2(utils::random_range(1), utils::random_range(1))
	);
}

void Cow::SetSpeed(float spd)
{
	speed = spd;
}