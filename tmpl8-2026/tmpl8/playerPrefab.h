#pragma once

#include "template.h"
#include <memory>

class GameObject;

struct PlayerPrefab
{
	std::unique_ptr<GameObject> Load(Tmpl8::vec2 pos);
};

