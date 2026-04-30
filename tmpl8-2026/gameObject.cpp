#include "gameObject.h"
#include "game.h"
#include "central.h"



void GameObject::Tick()
{
	if (sprite != nullptr)
	{
		Draw(x, y);
	}

	DrawOrigin();
	
}

void GameObject::Draw(float x, float y)
{
	// Draw from centre rather than top left
	sprite->Draw(surface, 
		x - sprite->GetWidth() / 2, 
		y - sprite->GetHeight() / 2
	);

};

void GameObject::DrawOrigin()
{
	surface->Box(x - 1, y + 1, x + 1, y - 1, 0xFF0000);
}

