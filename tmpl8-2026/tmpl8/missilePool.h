//#pragma once
//
//#include "gameObject.h"
//#include <vector>
//#include <memory>
//#include <queue>
//
//class GameObject;
//class Missile;
//class MissilePrefab;
//
//class Scene;
//
//
//class MissilePool
//{
//public:
//
//	void InstantiateToPool(Scene* scene, GameObject* player);
//
//	Missile* SpawnFromPool();
//
//	void ReturnToPool(Missile* m);
//
//
//	// Structors
//	MissilePool(int poolSize) : poolSize(poolSize) {};
//
//private:
//
//	int poolSize;
//
//	std::queue<Missile*> pool;
//	
//};
//
//
//
