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
	Collider* col = go->GetComponent<Collider>();
	if (col == nullptr) return false;

	// Cache pos
	float originalX = gameObject->x;
	float originalY = gameObject->y;

	// Move rect to check position
	UpdateRect(x, y);

	bool xCollision = (x1 > col->x1 && x1 < col->x2);
	bool yCollision = (y1 > col->y1 && y1 < col->y2);

	// Move rect back
	UpdateRect(originalX, originalY);

	if (xCollision && yCollision) return true;
	else return false;
};


// I want pixel-perfect collisions each time
// First check for collision at full distance
// Then check 1 pixel away
// Then check half distance
// Then keep halving until checked distance is within 1 px
// Then move to directly next to that pixel

void Collider::MoveAndCollide(float xDistance, float yDistance, span<GameObject> gameObjects)
{
	float& x = gameObject->x;
	float& y = gameObject->y;

	bool xCollide = false;
	bool yCollide = false;

	// Check x
	for (GameObject go : gameObjects)
	{
		// Phase 1 - check max distance
		
		// There has to be a better way to do this
		xCollide = CollideAt(x + xDistance, y, &go);
		
		if (!xCollide) continue;

		xCollide = CollideAt(roundf(x) + 1, y, &go);

		if (!xCollide) continue;
	}

	// Check y
	for (GameObject go : gameObjects)
	{
		// Phase 1 - check max distance
		yCollide = (CollideAt(x, y + yDistance, &go));

		if (!yCollide) return;



	}
	


	// X check
	

	// Y check

	// Make sure to move x and y separately

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