#pragma once

#include "game.h"
#include "surface.h"


using namespace Tmpl8;


class GameObject
{


private:

	Surface* surface;
	
	void Draw(float x, float y); // Draw sprite

	
	


public:

	// Position
	float x, y;

	Sprite* sprite;


	// Constructor
	GameObject(Surface* screen, Sprite* spr, float xPos, float yPos) 
		: surface(screen), sprite(spr), x(xPos), y(yPos)
	{
	};


	virtual void Tick(); // Per-frame logic




};

