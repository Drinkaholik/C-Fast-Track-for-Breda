#pragma once
#include "baseComponents.h"
#include "missilePool.h"
#include "missile.h"
#include "template.h"
#include <memory>

class Camera;

class MissileSpawner : public Component
{
public:

	void Start() override;
	void Tick() override;

	MissileSpawner(Scene* scene, GameObject* player) : scene(scene), player(player) {};

private:

	void SpawnMissiles();

	void SpawnSingle();
	void SpawnMultiGroup();
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

	// Time variables - measured in seconds
	float waitTime = 1; // how long to wait at start of level, and between waves
	float spawnDelay = 1; // Time before spawning next missile
	float delayCounter = spawnDelay;

	float warningTime = 1.0f; // Time between warning flashing and missile spawning


	float margin = 20; // How far offscreen to spawn missiles

	// Pointers
	Scene* scene;
	GameObject* player;


	// Owns the missile pool
	std::unique_ptr<MissilePool> pool = std::make_unique<MissilePool>(100);

	bool poolFilled = false;
};

