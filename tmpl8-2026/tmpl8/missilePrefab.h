#pragma once


#include "template.h"

class GameObject;
class Scene;
class ObjectPool;

class MissilePrefab
{
public:

	GameObject* Load(Scene* scene, ObjectPool* pool, Tmpl8::vec2 pos, GameObject* player, bool runStart);

};

