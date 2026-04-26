#pragma once

#include "game.h"
#include "surface.h"

using namespace Tmpl8;


class Central
{

public:

	inline static Game* game = nullptr; 
	inline static Surface* surface = nullptr;

	// Inline lets me include the definition in the header, so even though its technically defined
	// in every file that includes this header, the compiler knows they all refer to the same instance
	
	inline static const int screenWidth = 500;
	inline static const int screenHeight = 500;

	inline static float deltaTime = 0;

};

