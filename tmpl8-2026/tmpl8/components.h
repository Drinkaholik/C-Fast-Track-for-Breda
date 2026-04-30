#pragma once

#include "template.h"

// Simple bounding box collider
struct Collider
{
	float x1, y1; // Needed?

	int width, height;

	void DrawCollider();


	// Structors
	Collider(Sprite* sprite)
	{
		width = sprite->GetWidth();
		height = sprite->GetHeight();
	};

	Collider(int width, int height) : width(width), height(height)
	{
	};

	~Collider();
};


struct SpriteRenderer
{
	Surface* screen; // Points to main surface that's held by game.h, defined in constructor
	Sprite* sprite;

	int width, height;

	void Draw(float x, float y);


	//Structors
	SpriteRenderer(Surface* screen, Sprite* spr) : screen(screen), sprite(spr)
	{
		width = sprite->GetWidth();
		height = sprite->GetHeight();
	};

	~SpriteRenderer();

};
