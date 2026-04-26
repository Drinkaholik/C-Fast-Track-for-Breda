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

	// Sprite size
	int width, height;

	// Rect
	struct Rect
	{
		int x1, y1, x2, y2;
	} rect;

	Sprite* sprite;


	// Constructor
	GameObject(Surface* screen, Sprite* spr, float xPos, float yPos) 
		: surface(screen), sprite(spr), x(xPos), y(yPos) 
		//width(sprite->GetWidth()), height(sprite->GetHeight())
	{
		width = sprite->GetWidth();
		height = sprite->GetHeight();
		rect.x1 = x;
		rect.y1 = y;
		rect.x2 = x + width;
		rect.y2 = y + height;
	};


	virtual void Tick(); // Per-frame logic




};

