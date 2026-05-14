#pragma once

#include <vector>
#include <unordered_map>
#include <string>

// Gotta move to singleton pattern because colliders

class Collider;

class CollisionSystem
{
public:
	
	std::vector<Collider*>& GetLayer(std::string name);

	void Register(std::string name, Collider* col);

	void Deregister(std::string name, Collider* col);

	
private:

	std::vector<Collider*> layer1;
	std::vector<Collider*> layer2;
	std::vector<Collider*> layer3;

	std::unordered_map<std::string, std::vector<Collider*>> layers =
	{
		{ "cow", layer1 },
		{ "missile", layer2 },
		{ "player", layer3},

	};

};

