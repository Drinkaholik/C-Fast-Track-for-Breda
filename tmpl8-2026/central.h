#pragma once

#include "game.h"
#include "surface.h"

#include <vector>
#include <memory>

class GameObject;

using namespace Tmpl8;


class Central
{

public:

	static Game* game; 
	static Surface* surface;

	static std::vector<std::shared_ptr<GameObject>> spawnedObjects;
	
	
	static const int screenWidth = 500;
	static const int screenHeight = 500;

	static float deltaTime;

};

