#include "baseComponents.h"
#include "central.h"
#include "gameObject.h"
#include "utils.h"

#include <math.h>
#include <iostream>
#include <string>


using namespace std;


Component::~Component() = default;

// leaving it empty, but not gonna make it pure virtual cos not every component will need an update loop
void Component::Tick()
{
};




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

Collider::~Collider() = default;


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


bool Collider::CollideAt(float x, float y, GameObject* go)
{
	const Collider* col = go->GetComponent<Collider>();
	if (!col) return false;

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

void Collider::MoveAndCollide(float xDistance, float yDistance, span<shared_ptr<GameObject>> gameObjects)
{
	float& x = gameObject->x;
	float& y = gameObject->y;
	

	float targetX = x + xDistance;
	float targetY = y + yDistance;

	int xMoveSign = utils::sign(xDistance);
	int yMoveSign = utils::sign(yDistance);

	bool xCollide = false;
	bool yCollide = false;

	// Check for collisions against every collider in scene
	for (int i = 0; i < gameObjects.size(); i++) 
	{
		GameObject* go = gameObjects[i].get();

		for (int j = 0; j < abs(xDistance); j++)
		{
			xCollide = CollideAt(x + (j + 1 * xMoveSign), y, go);

			if (xCollide)
			{
				targetX = (x + (j) * xMoveSign);
				break;
			}
		}

		for (int j = 0; j < abs(yDistance); j++)
		{
			yCollide = CollideAt(x, y + (j + 1 * yMoveSign), go);

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


	
//	
//bool Collider::Sweep(GameObject* go, float& targetX, float& targetY, float distance, int colliderLength)
//{
//	// Immediately check targetX if its within collider
//
//	bool collisionAxis = false;
//
//	if (abs(distance) < colliderLength)
//	{
//		collisionAxis = CollideAt(targetX, targetY, go);
//		return collisionAxis; // Used to reduce nesting
//	}
//
//
//	// Otherwise begin sweep
//	int iterations = (abs(distance) / colliderLength); // Number of times to sweep. Int cast truncates so no problemo
//
//	for (int j = 0; j < iterations; j++)
//	{
//		// Exit j loop if no collision occurs
//		int checkX = targetX + (colliderLength * j);
//		collisionAxis = CollideAt(checkX, y, go);
//		if (!collisionAxis)
//		{
//			break; //!! Sweep will end here for most gameObjects in array !!// 
//		}
//
//
//
//		// If a collision occurs, find the pixel-perfect distance from the rect:
//
//		checkX = checkX - colliderLength / 2; // Move back by half
//		collisionAxis = CollideAt(checkX, y, go);
//
//
//		if (!collisionAxis) // If no collision, move forward by quarter
//		{
//			checkX = checkX + colliderLength / 4;
//			collisionAxis = CollideAt(checkX, y, go);
//
//
//			if (!collisionAxis)
//			{
//				int i = 0;
//				while (!collisionAxis) // Move forward pixel-by-pixel until collision occurs
//				{
//					i++;
//					checkX = checkX + i;
//					collisionAxis = CollideAt(checkX, y, go);
//				}
//				targetX = checkX - 1;
//			}
//
//			else
//			{
//				int i = 0;
//				while (collisionAxis) // Move backwards pixel-by-pixel until collision stops
//				{
//					i--;
//					checkX = checkX + i;
//					collisionAxis = CollideAt(checkX, y, go);
//				}
//				targetX = checkX;
//			}
//		}
//
//		else // If there's still a collision, keep moving back
//		{
//			checkX = checkX - colliderLength / 4; // Move back by quarter
//			collisionAxis = CollideAt(checkX, y, go);
//
//			if (collisionAxis)
//			{
//				int i = 0;
//				while (collisionAxis) // Move backwards pixel-by-pixel until collision stops
//				{
//					i--;
//					checkX = checkX + i;
//					collisionAxis = CollideAt(checkX, y, go);
//				}
//				targetX = checkX;
//			}
//
//			else
//			{
//				int i = 0;
//				while (!collisionAxis) // Move forward pixel-by-pixel until collision occurs
//				{
//					i++;
//					checkX = checkX + i;
//					collisionAxis = CollideAt(checkX, y, go);
//				}
//				targetX = checkX - 1;
//
//			}
//		}
//	}
//}
//


void Collider::DrawCollider(bool debug)
{
	if (!debug) return;
	Central::surface->Box(x1, y1, x2, y2, 0xFF0000);
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

//SpriteRenderer::SpriteRenderer(Sprite* spr, float xScale, float yScale)
//	: sprite(spr), xScale(xScale), yScale(yScale)
//{
//	width = sprite->GetWidth() * xScale;
//	height = sprite->GetHeight() * yScale;
//	screen = Central::surface;
//
//}

SpriteRenderer::~SpriteRenderer() = default;

void SpriteRenderer::Draw(float x, float y)
{
	// Draw from centre rather than top left
	sprite->Draw(screen,
		x - width / 2,
		y - height / 2
	);

	// Draw from centre rather than top left - causes write error
	/*sprite->DrawScaled(
		x - width / 2,
		y - height / 2,
		width, height, screen
	);*/
}

void SpriteRenderer::Tick()
{
	Draw(gameObject->x, gameObject->y);
}

#pragma endregion