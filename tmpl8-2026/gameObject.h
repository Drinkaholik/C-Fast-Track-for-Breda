#pragma once

#include "game.h"
#include "surface.h"
#include "components.h"

// Has a world-space position
// Can hold pointers to components like colliders and spriterenderers

using namespace std;

class GameObject
{

public:

	// Position
	float x, y;

	template <typename T> T* GetComponent()
	{
		for (unique_ptr<Component> c : components)
		{
			if c is T return c;
		}
		return nullptr;
	}

	


	virtual void Tick(); // Per-frame logic


	// Structors //
	// Basic:
	GameObject(float xPos, float yPos); // What is a collider-less, sprite-less go even good for?

	

	~GameObject();


private:

	vector<unique_ptr<Component>> components;

	void DrawOrigin(); // To test whether origin is correctly at centre of sprite, instead of top-left



};

