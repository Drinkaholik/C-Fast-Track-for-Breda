#pragma once

#include "baseComponents.h"
#include "template.h"
#include "objectPool.h"
#include <memory>

// Spawns cows in groups around a common centre - always offscreen
// Makes an initial on-screen spawn in Start()

// Also handles cow scaring
// Cows should become scared in 2 scenarios: if near an abduction, and if near a missile hitting the player

class Scene;
class GameObject;

class CowManager : public Component
{
public:

	void Start() override;
	void Tick() override;

	void SetPlayer(GameObject* go) { player = go; };


	// Structors
	CowManager(Scene* scene);


private:

	float spawnDelay = 3.0f; // Time between spawns
	float spawnMargin = 100.0f; // How far offscreen to spawn cows
	int groupCount = 2; // Number of groups to spawn at a time
	int groupRange = 1;

	int initialGroupCount = 5; // For the first spawn in Start()
	int initialGroupRange = 2;


#pragma region Group structs
	struct SpawnGroup
	{
		int size; // Avg number of cows to spawn
		int sizeRange; // Randomized

		float distance; // Avg distance from spawn centre
		float distanceRange; // Randomized

		float weight; // Spawn weight
	};

	static inline SpawnGroup smallGroup
	{
		2, 1,
		100.0f, 75.0f,
		0.3f
	};

	static inline SpawnGroup mediumGroup
	{
		6, 3,
		150.0f, 125.0f,
		0.6f
	};

	static inline SpawnGroup largeGroup
	{
		13, 4,
		200.0f, 175.0f,
		0.3f
	};

	static inline SpawnGroup groups[] =
	{
		smallGroup, mediumGroup, largeGroup
	};

	SpawnGroup currentGroup;
#pragma endregion


	// Spawn vars & functions
	float totalWeight;
	float count;

	Tmpl8::vec2 spawnCentre;
	bool spawnOnScreen = true; // Allows cows to be spawned on screen in start()
	
	void Spawn(int groupCount);

	void SetGroupSize();

	Tmpl8::vec2 SetSpawnCentre();
	Tmpl8::vec2 SetSpawnPos();


	// Pointers
	Scene* scene;
	GameObject* player;
	std::unique_ptr<ObjectPool> pool = std::make_unique<ObjectPool>(100);

};

