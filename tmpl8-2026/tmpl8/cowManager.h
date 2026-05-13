#pragma once

#include "baseComponents.h"
#include "template.h"

// Spawns cows in groups around a common centre - always offscreen

class Cow;

class CowManager : public Component
{

public:

	void Tick() override;


private:

	enum GroupSize
	{
		Small,
		Medium,
		Large
	} groupSize;

	// Small group
	int sGroup = 2; // Number of cows
	int sGroupRange = 1;

	float sGroupDistance = 100.0f; // Distance from spawn centre
	float sGroupDistanceRange = 75.0f;

	float sGroupWeight = 0.3f; // Spawn weight

	// Medium group
	int mGroup = 6;
	int mGroupRange = 3;

	float mGroupDistance = 150.0f;
	float mGroupDistanceRange = 125.0f;

	float mGroupWeight = 0.6f;


	// Large group
	int lGroup = 13;
	int lGroupRange = 4;

	float lGroupDistance = 200.0f;
	float lGroupDistanceRange = 175.0f;

	float lGroupWeight = 0.3f;


	int group;
	int groupRange;

	float groupDistance;
	float groupDistanceRange;


	Tmpl8::vec2 spawnCentre;
	Cow* cows;

	void Spawn(int group, int groupRange, float groupDistance, float groupDistanceRange);

	void SetGroupSize();

	Tmpl8::vec2 SetSpawnCentre();
	Tmpl8::vec2 SetSpawnPos();

};

