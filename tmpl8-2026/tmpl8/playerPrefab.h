#pragma once

#include <memory>

class GameObject;

struct PlayerPrefab
{
	std::shared_ptr<GameObject> Load(float xPos, float yPos);
};

