#pragma once

#include <vector>

// Gotta move to singleton pattern because colliders

class Collider;

class CollisionSystem
{
public:
	inline static std::vector<Collider*> colliders;


	inline static void Register(Collider* col)
	{
		colliders.push_back(col);
	}

	inline static void Deregister(Collider* col)
	{
		colliders.erase(std::remove(colliders.begin(), colliders.end(), col), colliders.end());
	}

};

