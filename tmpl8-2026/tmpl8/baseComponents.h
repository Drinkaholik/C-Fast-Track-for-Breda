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
	float x1, y1; // xMin, yMin
	float x2, y2; // xMax, yMax

	int width, height;

	void UpdateRect();

	// I really like snake_case here but PascalCase in other places...
	void DrawCollider(bool debug); // Bool set by gameObject

	

	// Check if current object would collide with another object at X position
	bool CollideAt(float x, float y, GameObject go); // Check against single object, faster
	bool CollideAt(float x, float y, std::span<GameObject> go); // Check against array

	// Same as CollideAt, but returns collision instance
	GameObject InstancePlace(float x, float y, GameObject go);
	GameObject InstancePlace(float x, float y, std::span<GameObject> go[]);


	void MoveAndCollide(float x, float y);

	void Tick() override;

	// Structors
	Collider(Sprite* sprite); // Initialize thru sprite size

	Collider(int width, int height); // Initialize with manual size

	~Collider() override;

};


struct SpriteRenderer : public Component
{
	Surface* screen; // Caches Central::surface - does that actually provide performance benefits? both are pointers
	Sprite* sprite;

	int width, height;

	void Draw(float x, float y);

	void Tick() override;


	//Structors
	SpriteRenderer(Sprite* spr);

	~SpriteRenderer() override;

};
