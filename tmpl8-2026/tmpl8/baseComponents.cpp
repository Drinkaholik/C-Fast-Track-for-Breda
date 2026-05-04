#include "baseComponents.h"
#include "central.h"
#include "gameObject.h"

#include <math.h>


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
	x1 = x - width / 2;
	y1 = y - height / 2;
	x2 = x + width / 2;
	y2 = y + height / 2;
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


// V1: (wouldn't work)
// I want pixel-perfect collisions each time
// First check for collision at full distance
// Then check 1 pixel away
// Then check half distance
// Then keep halving until checked distance is within 1 px
// Then move to directly next to that pixel

// V2:
// If the distance is lower than collider width / height, check it directly
// If its higher, sweep toward there in increments equal to the width / height
// If there is a collision, sweep backwards by half width/height
// Then sweep either forward or backwards by a quarter, and from there go 1 pixel at a time until 0 px from the collider

void Collider::MoveAndCollide(float xDistance, float yDistance, span<GameObject> gameObjects)
{
	float& x = gameObject->x;
	float& y = gameObject->y;

	float targetX = x + xDistance;
	float targetY = y + yDistance;

	bool xCollide = false;
	bool yCollide = false;

	
	for (int i = 0; i < gameObjects.size(); i++) // Insanely nested
	{
		// Check x
		GameObject* go = &gameObjects[i];

		// Immediately check targetX if its within collider
		if (abs(xDistance) < width)
			xCollide = CollideAt(targetX, y, go);

		else // Otherwise begin sweep
		{
			int iterations = (abs(xDistance) / width); // Number of times to sweep. Int cast truncates so no problemo

			for (int j = 0; j < iterations; j++)
			{
				// Exit j loop if no collision occurs
				int checkLoc = x + (width * j);
				xCollide = CollideAt(checkLoc, y, go);
				if (!xCollide)
				{
					break;
				}

				else // If collision occurs, begin half, quarter, pixel sweep
				{
					checkLoc = checkLoc - width / 2; // Move back by half
					xCollide = CollideAt(checkLoc, y, go);

					if (!xCollide) // Otherwise, start moving forward
					{
						checkLoc = checkLoc + width / 4; // Move forward by quarter
						xCollide = CollideAt(checkLoc, y, go);

						if (!xCollide)
						{
							int i = 0;
							while (!xCollide)
							{
								i++;
								checkLoc = checkLoc + i;
								xCollide = CollideAt(checkLoc, y, go);
							}
						}
					}

					else // If there's still a collision, keep moving back
					{
						checkLoc = checkLoc - width / 4; // Move back by quarter
						xCollide = CollideAt(checkLoc, y, go);

					}

				}




			}
		}
		
		
		
	}

	if (!xCollide) x = targetX;
	
	if (!yCollide) y = targetY;

	// Need to do a struct + constructor to declare a local function grrrr
	struct Sweep
	{
		Sweep(float xCheck, float yCheck, float distance, int size)
		{

		}
	};
	

}


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

	// Draw from centre rather than top left
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