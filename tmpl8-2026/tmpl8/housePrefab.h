#pragma once
#include "template.h"


class GameObject;
class Scene;

class HousePrefab
{
public:
	GameObject* Load(Scene* scene, Tmpl8::vec2 pos);

};

