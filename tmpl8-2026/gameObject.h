#pragma once

#include "game.h"
#include "surface.h"


using namespace Tmpl8;


class GameObject
{


private:

	Surface* surface;
	
	void Draw(float x, float y); // Draw sprite

	struct Transform
	{
		float x, y;
	};


public:

	Sprite* sprite;
	Transform transform;


	// Constructor
	GameObject(Surface* screen, Sprite* spr, float xPos, float yPos) 
		: surface(screen), sprite(spr)
	{
		transform.x = xPos;
		transform.y = yPos;
	};


	virtual void Tick(); // Per-frame logic




};

