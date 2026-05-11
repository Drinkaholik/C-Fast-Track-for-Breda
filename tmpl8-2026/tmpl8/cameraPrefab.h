#pragma once

#include <memory>

class GameObject;

struct CameraPrefab
{

	std::unique_ptr<GameObject> Load(float xPos, float yPos);

};

