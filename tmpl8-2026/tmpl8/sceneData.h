#pragma once

#include <array>
#include <vector>
#include <memory>

class GameObject;

struct SceneData
{
	virtual void LoadObjects(std::vector<std::shared_ptr<GameObject>>* vector) = 0;
};


