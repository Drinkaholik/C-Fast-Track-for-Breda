#pragma once

#include <memory>

class GameObject;

struct PlayerPrefab
{
	std::unique_ptr<GameObject> Load(float xPos, float yPos);
	std::unique_ptr<GameObject> Load(float xPos, float yPos, bool debug);
};

