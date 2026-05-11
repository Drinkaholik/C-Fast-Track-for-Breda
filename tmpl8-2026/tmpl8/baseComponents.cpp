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
	width = sprite->GetWidth();
	height = sprite->GetHeight();

	//UpdateRect(); // Cant be here because GameObject only gets set after constructor runs
}

Collider::Collider(int width, int height)
	: width(width), height(height)
{
};



void Collider::Tick()
{
	UpdateRect(gameObject->x, gameObject->y);
	DrawCollider(gameObject->debug);
}

void Collider::UpdateRect(float x, float y)
{
	x1 = round(x - width / 2);
	y1 = round(y - height / 2);
	x2 = round(x + width / 2);
	y2 = round(y + height / 2);
}


bool Collider::CollideAt(float x, float y, Collider* col)
{

	// Cache pos
	float originalX = gameObject->x;
	float originalY = gameObject->y;

	// Move rect to check position
	UpdateRect(x, y);

	const float colX1 = col->x1; // Apparently passing by value is more efficient here? 
	const float colX2 = col->x2; // Pointer / reference uses 8 bits whereas float uses 4
	const float colY1 = col->y1; // Is this more efficient than just directly accessing them
	const float colY2 = col->y2; // in the collision checks below?


	bool x1Collision = (x1 > colX1 && x1 < colX2);
	bool x2Collision = (x2 > colX1 && x2 < colX2);

	bool y1Collision = (y1 > colY1 && y1 < colY2);
	bool y2Collision = (y2 > colY1 && y2 < colY2);

	bool xCollision = x1Collision || x2Collision;
	bool yCollision = y1Collision || y2Collision;

	// Move rect back
	UpdateRect(originalX, originalY);

	if (xCollision && yCollision) return true;
	else return false;
};



// More efficient (probably) way:
// If the distance is lower than collider width / height, check it directly
// If its higher, sweep toward there in increments equal to the width / height
// If there is a collision, sweep backwards by half width/height
// Then sweep either forward or backwards by a quarter, and from there go 1 pixel at a time until 0 px from the collider

void Collider::MoveAndCollide(float xDistance, float yDistance)
{
	float& x = gameObject->x;
	float& y = gameObject->y;
	
	auto& colliders = CollisionSystem::colliders;

	float targetX = x + xDistance;
	float targetY = y + yDistance;

	int xMoveSign = utils::sign(xDistance);
	int yMoveSign = utils::sign(yDistance);

	bool xCollide = false;
	bool yCollide = false;

	// Check for collisions against every collider in scene
	for (int i = 0; i < colliders.size(); i++)
	{
		Collider* col = colliders[i];

		for (int j = 0; j < abs(xDistance); j++)
		{
			xCollide = CollideAt(x + (j + 1 * xMoveSign), y, col);

			if (xCollide)
			{
				targetX = (x + (j) * xMoveSign);
				break;
			}
		}

		for (int j = 0; j < abs(yDistance); j++)
		{
			yCollide = CollideAt(x, y + (j + 1 * yMoveSign), col);

			if (yCollide)
			{
				targetY = (y + (j) * yMoveSign);
				break;
			}
		}
	}

	x = targetX;

	y = targetY;
}


	

void Collider::DrawCollider(bool debug)
{
	if (!debug) return;

	if (Central::camera == nullptr) return;

	float xOffset = Central::camera->x;
	float yOffset = Central::camera->y;

	Central::surface->Box(x1 - xOffset, y1 - yOffset, x2 - xOffset, y2 - yOffset, 0xFF0000);
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