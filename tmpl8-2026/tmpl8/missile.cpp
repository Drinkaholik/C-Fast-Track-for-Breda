#include "missile.h"

#include "gameObject.h"
#include "missilePool.h"
#include "utils.h"
#include "central.h"

#include <random>

using namespace Tmpl8;
using namespace std;


void Missile::Spawn(vec2 pos)
{
	gameObject->pos = pos;
	SetSpeed();
	SetDirection();
}

void Missile::Tick()
{
	Move();
	Respawn();
}

void Missile::Move()
{
	gameObject->pos += direction * speed * Central::dts;
}

// Randomizes speed
void Missile::SetSpeed()
{
	speed *= 1 + utils::random_range(speedRange);
}


void Missile::SetDirection()
{
	vec2 dir = player->pos - gameObject->pos;

	dir = vec2::normalize(dir);

	dir.x += utils::random_range(angleRange);
	dir.y += utils::random_range(angleRange);

	direction = dir;

}

void Missile::Respawn()
{
	lifetime -= Central::dts;
	if (lifetime <= 0)
	{
		pool->ReturnToPool(this);
	}
}