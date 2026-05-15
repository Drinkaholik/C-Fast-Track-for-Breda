#include "missile.h"

#include "gameObject.h"
#include "objectPool.h"
#include "utils.h"
#include "central.h"

#include <random>
#include <cmath>
#include <iostream>
#include <string>

using namespace Tmpl8;
using namespace std;


void Missile::Spawn(vec2 pos)
{
	gameObject->pos = pos;
	SetSpeed();
	SetDirection();
	SetFrame();
	count = lifetime;
	
}

void Missile::Tick()
{
	Move();
	Despawn();
}

void Missile::Move()
{
	gameObject->pos += dir * speed * Central::dts;
}

// Randomizes speed
void Missile::SetSpeed()
{
	speed *= 1 + utils::random_range(speedRange);
}


void Missile::SetDirection()
{
	vec2 newDir = player->pos - gameObject->pos;

	newDir = vec2::normalize(newDir);

	newDir.x += utils::random_range(angleRange);
	newDir.y += utils::random_range(angleRange);

	dir = newDir;

}

void Missile::Despawn()
{
	count -= Central::dts;
	if (count <= 0)
	{
		pool->ReturnToPool(this->gameObject);
	}
}

// Changes missile sprite to match direction
void Missile::SetFrame()
{
	auto spr = gameObject->GetComponent<SpriteRenderer>();

	// Convert from vec2 to angle
	float radians = std::atan2(dir.y, dir.x);
	float angle = radians * (180.0f / (float)M_PI); // Trig stuff

	if (angle < 0.0f) angle += 360.0f; // Atan returns -180 to 180 so gotta correct
	angle += 22.5f; // Better aligns snapping

	int frame = (int)(angle / 45.0f);
	frame = (frame + 2) % 8; // Rotate clockwise by 90° and wrap if necessary

	cout << "angle: " << to_string(angle) << " , "
		<< "frame: " << to_string(frame) << endl;

	spr->SetFrame(frame);
}