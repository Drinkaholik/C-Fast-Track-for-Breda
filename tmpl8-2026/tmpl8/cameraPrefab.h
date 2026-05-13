#pragma once

#include "template.h"
#include "camera.h"
#include <memory>

class Scene;

class GameObject;

struct CameraPrefab
{

	GameObject* Load(Scene* scene, Tmpl8::vec2 pos);

};

