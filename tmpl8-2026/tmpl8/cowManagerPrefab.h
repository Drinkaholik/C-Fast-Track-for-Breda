#pragma once
#include "template.h"

class GameObject;
class Scene;

struct CowManagerPrefab
{
	GameObject* Load(Scene* scene, bool runStart);
};

