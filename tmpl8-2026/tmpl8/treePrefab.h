#pragma once
#include "template.h"


class GameObject;
class Scene;

class TreePrefab
{
public:
	GameObject* Load(Scene* scene, Tmpl8::vec2 pos, bool runStart);

};

