#pragma once

#include <memory>

class GameObject;

struct CameraPrefab
{

	std::shared_ptr<GameObject> Load(float xPos, float yPos);

};

