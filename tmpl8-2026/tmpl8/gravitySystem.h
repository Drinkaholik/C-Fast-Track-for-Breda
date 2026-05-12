#pragma once

#include <vector>

class GravBody;

class GravitySystem
{
public:
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