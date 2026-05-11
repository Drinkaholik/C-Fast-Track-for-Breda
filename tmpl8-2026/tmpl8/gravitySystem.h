#pragma once

#include <vector>

struct GravBody;

struct GravitySystem
{
	inline static std::vector<GravBody*> bodies;


	inline static void Register(GravBody* col)
	{
		bodies.push_back(col);
	}

	inline static void Deregister(GravBody* col)
	{
		bodies.erase(std::remove(bodies.begin(), bodies.end(), col), bodies.end());
	}

};