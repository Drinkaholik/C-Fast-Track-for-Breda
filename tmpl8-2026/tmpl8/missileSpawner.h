#pragma once
#include "baseComponents.h"
#include "objectPool.h"
#include "missile.h"
#include "template.h"
#include <memory>

class Scene;


class MissileSpawner : public Component
{
public:

	void Start() override;
	void Tick() override;

	void SetPlayer(GameObject* go) { player = go; };

	// Structors
	MissileSpawner(Scene* scene);

private:

	// Time variables - measured in seconds
	float waitTime = 1; // how long to wait at start of level, and between waves
	float spawnDelay = 0.2; // Time before spawning next missile
	float delayCounter = spawnDelay;

	float warningTime = 1.0f; // Time between warning flashing and missile spawning


	float margin = 20; // How far offscreen to spawn missiles


	void SpawnMissiles();

	void SpawnSingle();
	void SpawnMultiGroup(); // dont think i'll have time to implement the rest
	void SpawnMultiSpread();
	void SpawnSeriesGroup();
	void SpawnSeriesSpread();

	Tmpl8::vec2 SetSpawnPos(); // Sets relative spawn pos, not absolute

	enum AttackType
	{
		Single,

		// Simultaneous:
		Multi_Group, // From similar positions
		Multi_Spread, // From different positions

		// One after the other:
		Series_Group, 
		Series_Spread
	} attackType = AttackType::Single;




	// Pointers
	Scene* scene;
	GameObject* player = nullptr;


	// Owns the missile pool
	std::unique_ptr<ObjectPool> pool = std::make_unique<ObjectPool>(100);

	bool poolFilled = false;
};

