#pragma once

#include "baseComponents.h"
#include "template.h"

// Spawns cows in groups around a common centre - always offscreen

class Cow;

class CowManager : public Component
{

public:

	void Start() override;
	void Tick() override;

private:


	float spawnDelay; // Time between spawns


#pragma region Groups
	struct SpawnGroup
	{
		int groupSize; // Number of cows
		int sizeRange; // Randomized

		float distance; // Distance from spawn centre
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

	float totalWeight;

	Tmpl8::vec2 spawnCentre;
	Cow* cows;

	void Spawn();

	void SetGroupSize();

	Tmpl8::vec2 SetSpawnCentre();
	Tmpl8::vec2 SetSpawnPos();

};

