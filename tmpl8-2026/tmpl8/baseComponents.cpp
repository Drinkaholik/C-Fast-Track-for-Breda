#include "baseComponents.h"
#include "central.h"
#include "gameObject.h"


#pragma region Abstract classes 

Component::~Component() = default;
IUpdateable::~IUpdateable() = default;

#pragma endregion


#pragma region Collider

// Constructor
Collider::Collider(Sprite* sprite)
{
	width = sprite->GetWidth();
	height = sprite->GetHeight();

	UpdateRect();
}

Collider::Collider(int width, int height)
	: width(width), height(height)
{
	UpdateRect();
};

Collider::~Collider() = default;

void Collider::UpdateRect()
{
	x1 = gameObject->x - width / 2;
	y1 = gameObject->y - height / 2;
	x2 = gameObject->x + width / 2;
	y2 = gameObject->y + height / 2;
}

void Collider::DrawCollider(bool debug)
{
	if (!gameObject->debug) return;
	Central::surface->Box(x1, y1, x2, y2, 0xFF0000);
};

void Collider::Tick()
{
	UpdateRect();
}

#pragma endregion

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

}

#pragma endregion