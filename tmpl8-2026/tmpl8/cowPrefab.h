#pragma once

#include "template.h"

class GameObject;
class Scene;

struct CowPrefab
{
	GameObject* Load(Scene* scene, Tmpl8::vec2 pos);
};


