#pragma once

#include "template.h"

class GameObject;
class Scene;

struct PlayerPrefab
{
	GameObject* Load(Scene* scene, Tmpl8::vec2 pos, int maxHP, bool runStart);
};

