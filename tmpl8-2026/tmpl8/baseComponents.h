#pragma once

#include "template.h"
#include <span>

class GameObject; // Forward declaration to prevent circular dependancy

struct Component // Abstract struct
{
	GameObject* gameObject;

	virtual void Tick();

	virtual ~Component() = 0;
};



// Simple bounding box collider
struct Collider : public Component
{
	int x1, y1; // xMin, yMin
	int x2, y2; // xMax, yMax

	int width, height;

	void UpdateRect(float x, float y);

	// I really like snake_case here but PascalCase in other places...
	void DrawCollider(bool debug); // Bool set by gameObject

	

	// Check if current object would collide with another object at X position
	bool CollideAt(float x, float y, GameObject* go); // Check against single object, faster
	bool CollideAt(float x, float y, std::span<GameObject> gameObjects); // Check against array

	// Same as CollideAt, but returns collision instance
	GameObject InstancePlace(float x, float y, GameObject* go);
	GameObject InstancePlace(float x, float y, std::span<GameObject> gameObjects);

	// Move gameObject by nDistance, if it would not collide
	void MoveAndCollide(float xDistance, float yDistance, std::span<std::shared_ptr<GameObject>> gameObjects);

	bool Sweep(GameObject* go, float& targetX, float& targetY, float distance, int axisLength);


	void Tick() override;

	// Structors
	Collider(Sprite* sprite); // Initialize thru sprite size

	Collider(int width, int height); // Initialize with manual size

	~Collider() override;

};


struct SpriteRenderer : public Component
{
	Surface* screen; // Caches Central::surface - does that actually provide performance benefits? both are pointers. Apparently yes (cache misses?)
	Sprite* sprite;

	int width, height;

	//float xScale, yScale = 1.0f; // DrawScaled doesnt work properly...

	void Draw(float x, float y);

	void Tick() override;


	//Structors
	SpriteRenderer(Sprite* spr);
	/*SpriteRenderer(Sprite* spr, float xScale, float yScale);*/

	~SpriteRenderer() override;

};
