#include "components.h"



Collider::Collider(Sprite* sprite)
{

}


void SpriteRenderer::Draw(int x, int y)
{
	// Draw from centre rather than top left
	sprite->Draw(screen,
		x - sprite->GetWidth() / 2,
		y - sprite->GetHeight() / 2
	);

}