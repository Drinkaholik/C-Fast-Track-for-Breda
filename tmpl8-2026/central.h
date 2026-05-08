#pragma once

#include "game.h"
#include "surface.h"

#include <vector>
#include <memory>

class GameObject;
class GravBody;

using namespace Tmpl8;

// Holds 'global' references and values for easy access
// No need to split into separate structs / namespaces for a project of this size
// also don't see any need for singleton pattern atp


struct Central
{
	// Main references
	static Game* game; 
	static Surface* surface;

	// Camera
	static GameObject* camera;
	static const int screenWidth = 1000;
	static const int screenHeight = 1000;

	// Gameobjects
	static std::vector<std::shared_ptr<GameObject>> spawnedObjects;
	static std::vector<std::shared_ptr<GameObject>> gravBodies;
	
	
	// Time
	static float deltaTime;

};

