#include "collisionSystem.h"

#include <iostream>
#include <string>

using namespace std;

std::vector<Collider*>& CollisionSystem::GetLayer(std::string name)
{
	return layers[name];
}

void CollisionSystem::Register(std::string name, Collider* col)
{
	//cout << "I registered!!!" << endl;
	layers[name].push_back(col);
}

void CollisionSystem::Deregister(std::string name, Collider* col)
{
	auto& layer = layers[name];
	layer.erase(std::remove(layer.begin(), layer.end(), col), layer.end());
}