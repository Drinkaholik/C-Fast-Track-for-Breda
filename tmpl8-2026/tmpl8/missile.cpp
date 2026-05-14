#include "missile.h"

#include "gameObject.h"
#include "objectPool.h"
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
	count = lifetime;
}

void Missile::Tick()
{
	Move();
	Despawn();
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

void Missile::Despawn()
{
	count -= Central::dts;
	if (count <= 0)
	{
		pool->ReturnToPool(this->gameObject);
	}
}