#pragma once

#include "baseComponents.h"

#include <memory>

class GameObject;

class Prefab
{

public:
	virtual std::shared_ptr<GameObject> Load(float xPos, float yPos) = 0;

};

