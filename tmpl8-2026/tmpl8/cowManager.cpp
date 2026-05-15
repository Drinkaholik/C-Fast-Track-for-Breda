#include "cowManager.h"

#include "utils.h"
#include "cowPrefab.h"
#include "central.h"
#include "cow.h"
#include "scene.h"

using namespace Tmpl8;
using namespace std;

CowPrefab cowPrefab;



void CowManager::Start()
{

	pool->InstantiateToPool(cowPrefab, scene, pool.get(), vec2(0, 0), true);

	for (const SpawnGroup& s : groups) // For weighted spawn system
	{
		totalWeight += s.weight;
	}

	// Initial cow spawn
	int spawnAmount = initialGroupCount + (int)round(utils::random_range((float)initialGroupRange));
	Spawn(spawnAmount);

	spawnOnScreen = false;
}


void CowManager::Tick()
{
	count -= Central::dts;
	if (count > 0) return;

	int spawnAmount = groupCount + (int)round(utils::random_range((float)groupRange));

	Spawn(spawnAmount);
	RangeDespawn();
}



void CowManager::Abduct(Cow* cow) // Return cow to pool, scare nearby cows
{
	vec2 pos = cow->gameObject->pos;

	for (auto c : activeCows)
	{
		float radius = cow->GetRadius();
		float distance = utils::distance(c->gameObject->pos, pos);
		if (distance < radius)
		{
			c->SetScared(radius / distance);
		}
	}

	Despawn(cow);
	scene->GetScoreSystem()->IncrementScore();
}


void CowManager::SetGroupSize()
{
	// Uses weighted spawn
	float rWeight = Rand(totalWeight);
	float cumWeight = 0;

	for (const SpawnGroup& s : groups)
	{
		cumWeight += s.weight;
		if (cumWeight >= rWeight)
		{
			currentGroup = s;
			break;
		}
	}
}


void CowManager::Spawn(int groupCount)
{
	for (int i = 0; i < groupCount; i++)
	{
		// Set size and centre for each group
		SetGroupSize();
		spawnCentre = SetSpawnCentre();

		// Spawn cows for each group
		for (int j = 0; j < currentGroup.size + (int)round(utils::random_range((float)currentGroup.sizeRange)); j++)
		{
			auto go = pool->SpawnFromPool();
			if (go == nullptr) return;
			go->pos = SetSpawnPos();
			activeCows.insert(go->GetComponent<Cow>());
		}
	}
	count = spawnDelay;
}




float c = 1.0f;
void CowManager::RangeDespawn() // Despawn cow if they get too far from player
{
	// Only run once a sec
	c -= Central::dts;
	if (c > 0) return;
	c = 1.0f;

	auto it = activeCows.begin();
	while (it != activeCows.end())
	{
		auto cow = *it;
		float distance = utils::distance(cow->gameObject->pos, player->pos);
		if (distance >= despawnRange)
		{
			pool->ReturnToPool(cow->gameObject);
			it = activeCows.erase(it);
		}
		else it++;
	}
}

void CowManager::Despawn(Cow* cow)
{
	pool->ReturnToPool(cow->gameObject);
	activeCows.erase(cow);
}



vec2 CowManager::SetSpawnCentre()
{
	float y = 0;
	float x = 0;

	int screenWidth = Central::screenWidth;
	int screenHeight = Central::screenHeight;


	if (spawnOnScreen)
	{
		x = utils::random_range((float)screenWidth);
		y = utils::random_range((float)screenHeight);
	}

	else // Reuse code from missile spawner
	{

		if (utils::flip()) // Spawn in Y direction - top or bottom of screen
		{
			x = utils::random_range(screenWidth / 2 + spawnMargin);

			y = utils::rand_sign() * (screenHeight / 2 + spawnMargin);
		}

		else // Spawn in X direction - left or right of screen
		{
			x = utils::rand_sign() * (screenWidth / 2 + spawnMargin);

			y = utils::random_range(screenHeight / 2 + spawnMargin);
		}
	}

	return player->pos + vec2(x, y);
}


vec2 CowManager::SetSpawnPos()
{
	// Random spawnDir
	vec2 spawnDir = vec2::normalize(
		vec2(utils::random_range(1), utils::random_range(1))
	);

	float spawnDistance = currentGroup.distance + utils::random_range(currentGroup.distanceRange);

	return spawnCentre + spawnDir * spawnDistance;
}