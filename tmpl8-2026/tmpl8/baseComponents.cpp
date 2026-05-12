#include "baseComponents.h"
#include "central.h"
#include "gameObject.h"
#include "utils.h"
#include "collisionSystem.h"

#include <math.h>
#include <iostream>
#include <string>


using namespace std;


Component::~Component() = default;

// leaving them empty, but not gonna make it pure virtual cos not every component will need a start/update
void Component::Start() {};

void Component::Tick(){};



// Collider //
#pragma region Collider

// Constructors
Collider::Collider(Sprite* sprite)
{
	size.x = sprite->GetWidth();
	size.y = sprite->GetHeight();

	//UpdateRect(); // Cant be here because GameObject only gets set after constructor runs
}

Collider::Collider(vec2 size)
	: size(size)
{
};



void Collider::Tick()
{
	UpdateRect(gameObject->pos);
	DrawCollider(gameObject->debug);
}

void Collider::UpdateRect(vec2 pos)
{
	// round doesnt accept vec2
	p1.x = round(pos.x - size.x / 2);
	p1.y = round(pos.y - size.y / 2);
	p2.x = round(pos.x + size.x / 2);
	p2.y = round(pos.y + size.y / 2);
}


bool Collider::CollideAt(vec2 pos, Collider* col)
{

	// Cache pos
	vec2 originalPos = gameObject->pos;

	// Move rect to check position
	UpdateRect(pos);

	const vec2 colP1 = col->p1; // Vec2 and pointer are both 8 bytes, so does it matter whther I pass by value or ptr / ref?
	const vec2 colP2 = col->p2; // Pass by pointer would cause more cache misses ??


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



// More efficient (probably) way:
// If the distance is lower than collider width / height, check it directly
// If its higher, sweep toward there in increments equal to the width / height
// If there is a collision, sweep backwards by half width/height
// Then sweep either forward or backwards by a quarter, and from there go 1 pixel at a time until 0 px from the collider

void Collider::MoveAndCollide(vec2 distance)
{
	vec2& pos = gameObject->pos;
	
	auto& colliders = CollisionSystem::colliders;

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


	

void Collider::DrawCollider(bool debug)
{
	if (!debug) return;

	if (Central::camera == nullptr) return;

	vec2 offset = Central::camera->pos;

	Central::surface->Box(
		p1.x - offset.x, 
		p1.y - offset.y, 
		p2.x - offset.y, 
		p2.y - offset.y, 
		0xFF0000);
};



#pragma endregion





// SpriteRenderer //
#pragma region SpriteRenderer

SpriteRenderer::SpriteRenderer(Sprite* spr) : sprite(spr)
{
	width = sprite->GetWidth();
	height = sprite->GetHeight();
	screen = Central::surface;
};


//SpriteRenderer::~SpriteRenderer() = default;

void SpriteRenderer::Draw(float x, float y)
{

	if (Central::camera == nullptr) return;

	float xOffset = Central::camera->x;
	float yOffset = Central::camera->y;

	// Only draw if within viewport


	// Draw from centre rather than top left
	sprite->Draw(screen,
		x - width / 2 - xOffset,
		y - height / 2 - yOffset
	);

}

void SpriteRenderer::Tick()
{
	Draw(gameObject->x, gameObject->y);
}

#pragma endregion