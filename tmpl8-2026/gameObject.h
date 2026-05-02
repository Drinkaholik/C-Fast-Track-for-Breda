#pragma once

//#include "baseComponents.h"

#include <vector>
#include <memory>

struct Component;

// Has a world-space position
// Can hold pointers to components like colliders and spriterenderers

using namespace std;

class GameObject
{

public:

	// Position
	float x, y;

	bool debug; // Whether to draw origin, collider rect, etc


	template <typename T, typename... Args> T& AddComponent(Args&&... args);

	template <typename T> T* GetComponent();

	virtual void Tick(); // Per-frame logic


	// Constructor
	GameObject(float xPos, float yPos); // What is a collider-less, sprite-less go even good for?



private:

	vector<unique_ptr<Component>> components;

	void DrawOrigin(bool debug); // To test whether origin is correctly at centre of sprite, instead of top-left



};

