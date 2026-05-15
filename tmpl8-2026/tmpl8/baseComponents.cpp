#include "baseComponents.h"
#include "central.h"
#include "gameObject.h"
#include "utils.h"
#include "collisionSystem.h"
#include "scene.h"

#include <math.h>
#include <iostream>
#include <string>


using namespace std;
using namespace Tmpl8;


Component::~Component() = default;

// leaving them empty, but not gonna make it pure virtual cos not every component will need a start/update
void Component::Start() {};

void Component::Tick(){};



// Collider //
#pragma region Collider

// Constructors
Collider::Collider(Scene* scene, string layer, Sprite* sprite) : layer(layer)
{
	collisionSystem = scene->GetCollisionSystem();
	size.x = (float)sprite->GetWidth();
	size.y = (float)sprite->GetHeight();

	//UpdateRect(); // Cant be here because GameObject only gets set after constructor runs, set in first Tick
}

Collider::Collider(Scene* scene, string layer, vec2 size) : layer(layer), size(size)
{
	collisionSystem = scene->GetCollisionSystem();
};

Collider::~Collider()
{
	//collisionSystem->Deregister(this); // Causes an issue on program shutdown - need to fix later
}


void Collider::Start()
{
	UpdateRect(gameObject->pos);// Idk if it actually matters whether this runs in Start() or only in first Tick()
	collisionSystem->Register(layer, this);
}

void Collider::Tick()
{
	UpdateRect(gameObject->pos);
	DrawCollider();
}

void Collider::UpdateRect(vec2 pos)
{
	p1.x = round(pos.x - size.x / 2);
	p1.y = round(pos.y - size.y / 2);
	p2.x = round(pos.x + size.x / 2);
	p2.y = round(pos.y + size.y / 2);
}

bool Collider::CollideAt(const vec2 pos, Collider* col)
{
	// Cache pos
	vec2 originalPos = gameObject->pos;

	// Move rect to check position
	UpdateRect(pos);

	const vec2 colP1 = col->GetP1(); // Vec2 and pointer are both 8 bytes, so does it matter whther I pass by value or ptr / ref?
	const vec2 colP2 = col->GetP2(); // Pass by pointer would cause more cache misses ??

	// AABB logic
	bool x1Collision = (p1.x > colP1.x && p1.x < colP2.x);
	bool x2Collision = (p2.x > colP1.x && p2.x < colP2.x);

	bool y1Collision = (p1.y > colP1.y && p1.y < colP2.y);
	bool y2Collision = (p2.y > colP1.y && p2.y < colP2.y);

	bool xCollision = x1Collision || x2Collision;
	bool yCollision = y1Collision || y2Collision;

	// Move rect back
	UpdateRect(originalPos);

	if (xCollision && yCollision) return true;
	else return false;
};

bool Collider::CollideAt(Tmpl8::vec2 pos, std::string layer)
{
	// Cache pos
	vec2 originalPos = gameObject->pos;

	for (auto& col : collisionSystem->GetLayer(layer))
	{
		// Move rect to check position
		UpdateRect(pos);

		const vec2 colP1 = col->GetP1(); // Vec2 and pointer are both 8 bytes, so does it matter whther I pass by value or ptr / ref?
		const vec2 colP2 = col->GetP2(); // Pass by pointer would cause more cache misses ??

		// AABB logic
		bool x1Collision = (p1.x > colP1.x && p1.x < colP2.x);
		bool x2Collision = (p2.x > colP1.x && p2.x < colP2.x);

		bool y1Collision = (p1.y > colP1.y && p1.y < colP2.y);
		bool y2Collision = (p2.y > colP1.y && p2.y < colP2.y);

		bool xCollision = x1Collision || x2Collision;
		bool yCollision = y1Collision || y2Collision;

		// Move rect back
		UpdateRect(originalPos);

		
		if (xCollision && yCollision)
		{
			//cout << "I'm colliding!!!" << endl;
			return true;
		}
	}
	return false;
}


Collider* Collider::CollideWith(const vec2 pos, Collider* col)
{
	// Cache pos
	vec2 originalPos = gameObject->pos;

	// Move rect to check position
	UpdateRect(pos);

	const vec2 colP1 = col->GetP1(); // Vec2 and pointer are both 8 bytes, so does it matter whther I pass by value or ptr / ref?
	const vec2 colP2 = col->GetP2(); // Pass by pointer would cause more cache misses ??

	// AABB logic
	bool x1Collision = (p1.x > colP1.x && p1.x < colP2.x);
	bool x2Collision = (p2.x > colP1.x && p2.x < colP2.x);

	bool y1Collision = (p1.y > colP1.y && p1.y < colP2.y);
	bool y2Collision = (p2.y > colP1.y && p2.y < colP2.y);

	bool xCollision = x1Collision || x2Collision;
	bool yCollision = y1Collision || y2Collision;

	// Move rect back
	UpdateRect(originalPos);

	if (xCollision && yCollision) return col;
	else return nullptr;
};


Collider* Collider::CollideWith(Tmpl8::vec2 pos, std::string layer)
{
	// Cache pos
	vec2 originalPos = gameObject->pos;

	for (auto& col : collisionSystem->GetLayer(layer))
	{
		// Move rect to check position
		UpdateRect(pos);

		const vec2 colP1 = col->GetP1(); // Vec2 and pointer are both 8 bytes, so does it matter whther I pass by value or ptr / ref?
		const vec2 colP2 = col->GetP2(); // Pass by pointer would cause more cache misses ??

		// AABB logic
		bool x1Collision = (p1.x > colP1.x && p1.x < colP2.x);
		bool x2Collision = (p2.x > colP1.x && p2.x < colP2.x);

		bool y1Collision = (p1.y > colP1.y && p1.y < colP2.y);
		bool y2Collision = (p2.y > colP1.y && p2.y < colP2.y);

		bool xCollision = x1Collision || x2Collision;
		bool yCollision = y1Collision || y2Collision;

		// Move rect back
		UpdateRect(originalPos);


		if (xCollision && yCollision)
		{
			//cout << "I'm colliding!!!" << endl;
			return col;
		}
	}
	return nullptr;
}




void Collider::MoveAndCollide(string layer, vec2 distance)
{
	vec2& pos = gameObject->pos;
	
	auto& colliders = collisionSystem->GetLayer(layer);

	vec2 targetPos = pos + distance;
	int xMoveSign = utils::sign(distance.x);
	int yMoveSign = utils::sign(distance.y);

	bool xCollide = false;
	bool yCollide = false;

	// Check for collisions against every collider in scene
	for (int i = 0; i < colliders.size(); i++)
	{
		Collider* col = colliders[i];

		for (int j = 0; j < abs(distance.x); j++)
		{
			xCollide = CollideAt(
				vec2(pos.x + (j + 1 * xMoveSign), pos.y),
				col);

			if (xCollide)
			{
				targetPos.x = (pos.x + (j) * xMoveSign);
				break;
			}
		}

		for (int j = 0; j < abs(distance.y); j++)
		{
			yCollide = CollideAt(
				vec2(pos.x, pos.y + (j + 1 * yMoveSign)),
				col);

			if (yCollide)
			{
				targetPos.y = (pos.y + (j) * yMoveSign);
				break;
			}
		}
	}

	// Handle x and y separately
	pos.x = targetPos.x;

	pos.y = targetPos.y;
}

void Collider::DrawCollider()
{
	if (!gameObject->debug) return;

	if (Central::camera == nullptr) return;

	vec2 offset = Central::camera->pos;

	Central::surface->Box(
		(int)round(p1.x - offset.x),
		(int)round(p1.y - offset.y),
		(int)round(p2.x - offset.x),
		(int)round(p2.y - offset.y),
		0xFF0000);
};

#pragma endregion


// SpriteRenderer //
#pragma region SpriteRenderer

SpriteRenderer::SpriteRenderer(Sprite* spr) : sprite(spr)
{
	size.x = (float)sprite->GetWidth();
	size.y = (float)sprite->GetHeight();
	screen = Central::surface;
	camera = Central::camera;

	frameCount = sprite->Frames();
};

void SpriteRenderer::Draw(vec2 pos)
{

	if (camera == nullptr) camera = Central::camera; // In case of init issues

	vec2 camOffset = Central::camera->pos;
	vec2 originOffset = size * 0.5; // Ensures origin is centre, not top-left

	vec2 screenPos = pos - originOffset - camOffset;

	// Only draw if within viewport


	// Draw from centre rather than top left
	sprite->Draw(screen,
		(int)round(screenPos.x),
		(int)round(screenPos.y)
	);

}

void SpriteRenderer::Tick()
{
	Draw(gameObject->pos);
}

#pragma endregion



// Image //


void Image::Draw(vec2 pos)
{

	sprite->Draw(screen, 
		(int)round(pos.x), 
		(int)round(pos.y));
}