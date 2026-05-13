#pragma once

#include "missile.h"
#include "missilePrefab.h"
#include "template.h"
#include "gameObject.h"
#include <vector>
#include <memory>


class MissilePool
{
public:

	void InstantiateToPool(GameObject* player);

	void SpawnFromPool(Missile* m, Tmpl8::vec2 pos);

	void ReturnToPool(Missile* m);


	// Structors
	//MissilePool(int poolSize) : poolSize(poolSize) {};

private:

	MissilePrefab missilePrefab;

	int poolSize;

	//GameObject* pool[];
	
};



