#include "baseComponents.h"
#include "central.h"
#include "gameObject.h"




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
	UpdateRect();
};

Collider::~Collider() = default;


void Collider::Tick()
{
	UpdateRect();
	DrawCollider(gameObject->debug);
}

void Collider::UpdateRect()
{
	x1 = gameObject->x - width / 2;
	y1 = gameObject->y - height / 2;
	x2 = gameObject->x + width / 2;
	y2 = gameObject->y + height / 2;
}


bool Collider::CollideAt(float x, float y, GameObject* go)
{
	Collider* col = go->GetComponent<Collider>();
	if (col == nullptr) return false;

	// Cache references
	float& xPos = gameObject->x;
	float& yPos = gameObject->y;

	float originalX = xPos;
	float originalY = yPos;

	// Move this gameObject to position
	xPos = x;
	yPos = y;
	UpdateRect();

	bool xCollision = (x1 > col->x1 && x1 < col->x2);
	bool yCollision = (y1 > col->y1 && y1 < col->y2);

	// Move back
	xPos = originalX;
	yPos = originalY;
	UpdateRect();

	if (xCollision && yCollision) return true;
	else return false;

};


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

SpriteRenderer::~SpriteRenderer() = default;

void SpriteRenderer::Draw(float x, float y)
{
	// Draw from centre rather than top left
	sprite->Draw(screen,
		x - sprite->GetWidth() / 2,
		y - sprite->GetHeight() / 2
	);
}

void SpriteRenderer::Tick()
{
	Draw(gameObject->x, gameObject->y);
}

#pragma endregion