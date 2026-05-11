#pragma once

#include <vector>

struct Collider;

struct CollisionSystem
{
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

