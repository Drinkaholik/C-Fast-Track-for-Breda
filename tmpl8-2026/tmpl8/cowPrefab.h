#pragma once

#include "template.h"

class GameObject;
class Scene;
class ObjectPool;

class CowPrefab
{
public:
	GameObject* Load(Scene* scene, ObjectPool* pool, Tmpl8::vec2 pos, bool runStart);
};


