#pragma once

#include "template.h"
#include <span>

class GameObject; // Forward declaration to prevent circular dependancy

class Component // Abstract struct
{
public:

	GameObject* gameObject; // Pointer instead of ref so I don't need to pass go in constructor, would add extra boilerplate
	virtual void Start();
	virtual void Tick();

	virtual ~Component() = 0;
};



// Simple bounding box collider
class Collider : public Component
{
public:

	Tmpl8::vec2 p1; // xMin, yMin
	Tmpl8::vec2 p2; // xMax, yMax

	void Start() override;
	void Tick() override;

	// Check if current object would collide with another object at X position
	bool CollideAt(Tmpl8::vec2 pos, Collider* go); // Check against single object, faster
	bool CollideAt(Tmpl8::vec2 pos); // Check against system's collider array

	// Same as CollideAt, but returns collision instance
	GameObject CollideWith(Tmpl8::vec2 pos, Collider* go);
	GameObject CollideWith(Tmpl8::vec2 pos);

	// Move gameObject by nDistance, if it would not collide
	void MoveAndCollide(Tmpl8::vec2 distance);




	// Structors
	Collider(Sprite* sprite); // Initialize thru sprite size

	Collider(Tmpl8::vec2 size); // Initialize with manual size

	~Collider(); // Used to deregister from CollisionSystem::colliders

private:

	Tmpl8::vec2 size; // width, height

	void UpdateRect(Tmpl8::vec2 pos);

	// I really like snake_case here but PascalCase in other places...
	void DrawCollider(); // Bool set by gameObject

};


// Sprites live in world-space
class SpriteRenderer : public Component
{
public:
	
	void Tick() override;

	void ChangeSprite(Sprite* spr)
	{
		sprite = spr;
	}

	void SetFrame(int frame)
	{
		frame = Tmpl8::Clamp(frame, 0, frameCount);
		currentFrame = frame;

		sprite->SetFrame(currentFrame);
	}

	void IncrementFrame(int amount)
	{
		int newFrame = currentFrame += amount;
		newFrame = Tmpl8::Clamp(newFrame, 0, frameCount);
	}

	//Structors
	SpriteRenderer(Sprite* spr);

private:

	int frameCount;
	int currentFrame = 0;

	Surface* screen; // Caches Central::surface - does that actually provide performance benefits? both are pointers. Apparently yes (cache misses?)
	Sprite* sprite;

	Tmpl8::vec2 size;

	void Draw(Tmpl8::vec2 pos);
};



// Images live in screen-space
class Image : public Component
{
public:

	void Tick() override;

	void ChangeImage(Sprite* spr)
	{
		sprite = spr;
	}

	// Structors
	Image(Sprite* spr) : sprite(spr), screen(Central::surface) {};

private:

	Surface* screen;
	Sprite* sprite;
};
