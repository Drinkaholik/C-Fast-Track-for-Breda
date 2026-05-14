#pragma once

#include "game.h"
#include "surface.h"

#include <vector>
#include <memory>

class GameObject;

// Holds 'global' references and values for easy access
// No need to split into separate structs / namespaces for a project of this size
// also don't see any need for singleton pattern atp


struct Central
{
	// Main references
	static Tmpl8::Game* game; 
	static Tmpl8::Surface* surface;

	// Camera
	static GameObject* camera;
	static const int screenWidth = 1500;
	static const int screenHeight = 1000;
	
	// Time
	static float deltaTime; // Delta time in milliseconds
	static float dts; // Delta time in seconds

};

