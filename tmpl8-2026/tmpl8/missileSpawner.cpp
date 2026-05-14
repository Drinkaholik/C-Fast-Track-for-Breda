#include "missileSpawner.h"

#include "camera.h"
#include "utils.h"
#include "missilePrefab.h"
#include <iostream>
#include <string>

using namespace std;
using namespace Tmpl8;

MissilePrefab missilePrefab;

void MissileSpawner::Start()
{
	pool->InstantiateToPool(missilePrefab, scene, pool.get(), vec2(0, 0), player);
}

void MissileSpawner::Tick()
{
	//if (!poolFilled)
	//{
	//	// DO NOT put in start()!!!!!!!! - resizing the sceneObjects vector 
	//	// while its still being iterated over causes dangling references
	//	pool->InstantiateToPool(scene, player); 
	//	poolFilled = true;
	//}

	// Ok yeah idk whats going on
	// I mean we iterate in Tick() too so obviously that cant be the main issue
	
	delayCounter -= Central::dts; // Count down till next spawn
	if (delayCounter <= 0) SpawnSingle();
	
}



//void MissileSpawner::SpawnMissiles()
//{
//	switch (attackType)
//	{
//	case AttackType::Single:
//		SpawnSingle();
//		break;
//
//	case AttackType::Multi_Group:
//		SpawnMultiGroup();
//		break;
//
//	case AttackType::Multi_Spread:
//		SpawnMultiSpread();
//		break;
//
//	case AttackType::Series_Group:
//		SpawnSeriesGroup();
//		break;
//
//	case AttackType::Series_Spread:
//		SpawnSeriesSpread();
//		break;
//	}
//}


void MissileSpawner::SpawnSingle()
{
	// Reset timer
	delayCounter = spawnDelay;

	float count = warningTime;

	vec2 relSpawn = SetSpawnPos(); // Used to place warning icon

	// Time between warning icon and missile spawn
	while (count > 0) count -= Central::dts;

	vec2 playerPos = player->pos;

	vec2 realSpawn = playerPos - relSpawn;

	cout << "relativeSpawn - " << "x: " << to_string(relSpawn.x) << " , " << "y: " << to_string(relSpawn.y) << endl
		<< "cameraPosition - " << "x: " << to_string(playerPos.x) << " , " << "y: " << to_string(playerPos.y) << endl
		<< "realSpawn - " << "x: " << to_string(realSpawn.x) << " , " << "y: " << to_string(realSpawn.y) << endl << endl;

	// Spawn object
	auto* m = pool->SpawnFromPool();
	m->GetComponent<Missile>()->Spawn(realSpawn); // kinda expensive to do a GetComponent() call every time I spawn a missile

	
}

/*
Two cases:
1. It spawns from the top or the bottom of the screen.

- This means:
- - Y = +- (screenHeight / 2) + margin
- - X = randomRange(-screenWidth/2, screenWidth/2)


2. It spawns from the left or right of the screen

- This means:
- - Y = randomRange(screenHeight/2, screenHeight/2)
- - X = +- (screenWidth / 2) + margi´n
*/

// Sets the relative spawn pos from camera - aka distance to camera, not position
vec2 MissileSpawner::SetSpawnPos()
{

	bool flip = (int)round(Rand(1)); // Randomly sets flip to either 0 or 1

	//cout << "flip: " << to_string(flip) << endl;

	float y = 0;
	float x = 0;

	int screenWidth = Central::screenWidth;
	int screenHeight = Central::screenHeight;

	int sign = utils::sign(
		Rand(1) - 0.5f // Returns a number between -0.5 and 0.5
	);

	//cout << "sign: " << to_string(sign) << endl;

	if (flip) // Spawn in Y direction - top or bottom of screen
	{
		x = utils::random_range(screenWidth / 2 + margin);

		y = sign * (screenHeight / 2 + margin);
	}

	else // Spawn in X direction - left or right of screen
	{
		x = sign * (screenWidth / 2 + margin);
		
		y = utils::random_range(screenHeight / 2 + margin);
	}

	return vec2(x, y);
};

