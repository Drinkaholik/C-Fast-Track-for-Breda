#pragma once

#include "game.h"
#include "surface.h"

// Has a world-space position and a sprite

using namespace Tmpl8;
using namespace std;


class GameObject
{

public:

	// Position
	float x, y;

	// Sprite size
	int width, height;

	// Rect
	struct Rect
	{
		float x1, y1, x2, y2;
	} rect;

	Sprite* sprite;


	void move_and_collide();


	void updateRect()
	{
		rect.x1 = x - width / 2;
		rect.y1 = y - height / 2;
		rect.x2 = x + width / 2;
		rect.y2 = y + height / 2;
	}


	virtual void Tick(); // Per-frame logic


	// Constructor
	// Spriteless:
	GameObject(Surface* screen, float xPos, float yPos);

	// With sprite:
	GameObject(Surface* screen, Sprite* spr, float xPos, float yPos)
		: surface(screen), sprite(spr), x(xPos), y(yPos)
		
	{
		width = sprite->GetWidth(); 
		height = sprite->GetHeight();
		updateRect();
	};


protected:
	Surface* surface; // Points to main surface that's held by game.h, defined in constructor

private:

	void DrawOrigin(); // To test whether origin is correctly at centre of sprite, instead of top-left

	void Draw(float x, float y); // Draw sprite


};

