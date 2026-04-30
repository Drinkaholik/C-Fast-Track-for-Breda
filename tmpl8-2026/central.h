#pragma once

#include "game.h"
#include "surface.h"

using namespace Tmpl8;


class Central
{

public:

	static Game* game; 
	static Surface* surface;

	
	static const int screenWidth = 500;
	static const int screenHeight = 500;

	static float deltaTime;

};

