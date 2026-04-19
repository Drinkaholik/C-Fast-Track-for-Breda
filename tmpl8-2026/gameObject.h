#pragma once

#include "game.h"
#include "surface.h"


using namespace Tmpl8;


class GameObject
{
public:

	Sprite* sprite;

	struct Transform
	{
		float x;
		float y;

	} transform;


	// Constructor
	GameObject(Sprite spr, float xPos, float yPos)
	{
		sprite = &spr;
		transform.x = xPos;
		transform.y = yPos;
	};


	virtual void Tick(); // Runtime logic

	void Draw(); // Draw sprite




};
