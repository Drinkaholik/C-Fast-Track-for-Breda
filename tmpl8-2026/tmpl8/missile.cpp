#include "missile.h"

#include "gameObject.h"
#include "utils.h"
#include "central.h"

#include <random>

using namespace Tmpl8;
using namespace std;


void Missile::Spawn(vec2 pos)
{
	SetSpeed();
	SetDirection();
}

void Missile::Tick()
{
	Move();
}

void Missile::Move()
{
	gameObject->pos += direction * speed * Central::deltaTime;
}

// Randomizes speed
void Missile::SetSpeed()
{
	speed += utils::random_range(speedRange);
}


void Missile::SetDirection()
{
	vec2 dir = player->pos - gameObject->pos;

	dir = vec2::normalize(dir);

	dir.x += utils::random_range(angleRange);
	dir.y += utils::random_range(angleRange);

	direction = dir;

}

