#pragma once


#include "template.h"

class GameObject;
class Scene;
class MissilePool;

class MissilePrefab
{
public:

	GameObject* Load(Scene* scene, MissilePool* pool, Tmpl8::vec2 pos, GameObject* player);

};

