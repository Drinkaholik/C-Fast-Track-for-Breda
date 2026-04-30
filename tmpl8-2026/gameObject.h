#pragma once

#include "game.h"
#include "surface.h"
#include "components.h"

// Has a world-space position
// Can hold pointers to components like colliders and spriterenderers


class GameObject
{

public:

	// Position
	float x, y;

	std::unique_ptr<SpriteRenderer> spriteRenderer;
	std::unique_ptr<Collider> collider;





	virtual void Tick(); // Per-frame logic


	// Structors //
	// Basic:
	GameObject(float xPos, float yPos); // What is a collider-less, sprite-less go even good for?

	// With collider:
	GameObject(float xPos, float yPos, int height, int width)
		: x(xPos), y(yPos)
	{
		collider = std::make_unique<Collider>(width, height);
	}

	// With sprite:
	GameObject(float xPos, float yPos, Sprite* spr)
		: x(xPos), y(yPos)
	{
		spriteRenderer = std::make_unique<SpriteRenderer>(spr);
	};

	~GameObject();


private:

	void DrawOrigin(); // To test whether origin is correctly at centre of sprite, instead of top-left



};

