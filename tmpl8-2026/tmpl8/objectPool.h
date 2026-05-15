#pragma once

#include "gameObject.h"
#include <vector>
#include <memory>
#include <queue>


// Pooler for any kinds of gameobjects
// Instantiate to pool needs to be a variadic template to pass the correct prefab arguments

class GameObject;
class Scene;


class ObjectPool
{
public:

	// If this works first try I'm an actual goat
	// I'm an actual goat!!!!!
	// This works with and without the &&, so do I actually need it?
	// I think it ensures the passed parameter is cv-unqualified? but idc about that i think
	template <typename First, typename... Args> 
	void InstantiateToPool(First prefab, Scene* scene, Args... args)
	{
		for (int i = 0; i < poolSize; i++)
		{
			auto go = prefab.Load(scene, std::forward<Args>(args)...);
			go->SetActive(false);
			pool.push(go);
		}
	}
	

	GameObject* SpawnFromPool();

	void ReturnToPool(GameObject* go);


	// Structors
	ObjectPool(int poolSize) : poolSize(poolSize) {};

private:

	int poolSize;

	std::queue<GameObject*> pool;

};



