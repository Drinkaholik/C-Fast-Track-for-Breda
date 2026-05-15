#pragma once

#include "template.h"
#include <span>
#include <string>
#include <memory>

class GameObject; // Forward declaration to prevent circular dependancy
class CollisionSystem;
class Scene;

class Component // Abstract struct
{
public:

	GameObject* gameObject; // Pointer instead of ref so I don't need to pass go in constructor, would add extra boilerplate
	bool active = true;

	virtual void Start();
	virtual void Tick();

	virtual ~Component() = 0;
};



// Simple bounding box collider
class Collider : public Component
{
public:

	void Start() override;
	void Tick() override;


	// Check if current object would collide with another object at X position
	bool CollideAt(Tmpl8::vec2 pos, Collider* go); // Check against single object, faster
	bool CollideAt(Tmpl8::vec2 pos, std::string layer); // Check against system's collider array

	// Same as CollideAt, but returns collision instance
	Collider* CollideWith(Tmpl8::vec2 pos, Collider* go);
	Collider* CollideWith(Tmpl8::vec2 pos, std::string layer);

	// Move gameObject by nDistance, if it would not collide
	void MoveAndCollide(std::string layer, Tmpl8::vec2 distance);



	Tmpl8::vec2 GetP1() { return p1; }
	Tmpl8::vec2 GetP2() { return p2; }

	void SetCollisionSystem(CollisionSystem* system)
	{
		collisionSystem = system;
	}


	// Structors
	Collider(Scene* scene, std::string layer, Tmpl8::Sprite* sprite); // Initialize thru sprite size

	Collider(Scene* scene, std::string layer, Tmpl8::vec2 size); // Initialize with manual size

	~Collider(); // Used to deregister from CollisionSystem::colliders


private:

	Tmpl8::vec2 p1; // xMin, yMin
	Tmpl8::vec2 p2; // xMax, yMax

	Tmpl8::vec2 size; // width, height

	CollisionSystem* collisionSystem;
	std::string layer;

	

	
	void UpdateRect(Tmpl8::vec2 pos);

	// I really like snake_case here but PascalCase in other places...
	void DrawCollider(); // Bool set by gameObject

};


// Sprites live in world-space
class SpriteRenderer : public Component
{
public:
	
	// Specifically not override so it won't be called by gameObject->Tick()
	// Gets called by the renderSystem instead
	virtual void Tick(); 


	void SetFrame(int frame)
	{
		currentFrame = Tmpl8::Clamp(frame, 0, frameCount - 1);
		sprite->SetFrame(currentFrame);
	}

	void IncrementFrame(int amount)
	{
		int newFrame = currentFrame += amount;
		newFrame = Tmpl8::Clamp(newFrame, 0, frameCount);
	}

	int GetFrame() { return currentFrame; };

	int GetFrameCount() { return frameCount; };

	Tmpl8::Sprite* GetSprite() { return sprite.get(); };

	//Structors
	SpriteRenderer(std::string spriteName);
	SpriteRenderer(std::string spriteName, int frame);

protected:

	int frameCount;
	int currentFrame = 0;

	Tmpl8::Surface* screen;
	GameObject* camera;
	std::unique_ptr<Tmpl8::Sprite> sprite;

	Tmpl8::vec2 size;

	virtual void Draw(Tmpl8::vec2 pos);
	void SetSprite(std::string spriteName);
};




// Images live in screen-space
class Image : public SpriteRenderer
{
public:

	void Tick() override;


	// Structors
	//Image(std::string spriteName) : SpriteRenderer::SpriteRenderer(std::string spriteName);

private:

	void Draw(Tmpl8::vec2 pos) override;


};
