#pragma once

#include "game.h"
#include "surface.h"

#include <vector>
#include <memory>

class GameObject;
class GravBody;

using namespace Tmpl8;


class Central
{

public:

	static Game* game; 
	static Surface* surface;

	static std::vector<std::shared_ptr<GameObject>> spawnedObjects;

	static std::vector<std::shared_ptr<GameObject>> gravBodies;
	
	
	static const int screenWidth = 500;
	static const int screenHeight = 500;

	static float deltaTime;

};

