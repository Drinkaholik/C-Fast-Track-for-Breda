#pragma once

#include "template.h"
#include "gameObject.h"

struct Component // Abstract struct
{
	GameObject* owner;

	virtual ~Component();
};


// Simple bounding box collider
struct Collider : public Component
{
	float x1, y1; // Needed?

	int width, height;

	void draw_collider();

	void move_and_collide();

	// Check if current object would collide with another object at X position
	bool collide_at(float x, float y, GameObject go); // Check against single object, faster
	bool collide_at(float x, float y, GameObject go[]); // Check against array



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


struct SpriteRenderer : public Component
{
	Surface* screen; // Points to main surface that's held by game.h, defined in constructor
	Sprite* sprite;

	int width, height;

	void Draw(float x, float y);


	//Structors
	SpriteRenderer(Sprite* spr) : screen(screen), sprite(spr)
	{
		width = sprite->GetWidth();
		height = sprite->GetHeight();
	};

	~SpriteRenderer();

};
