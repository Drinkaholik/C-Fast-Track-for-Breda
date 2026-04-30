#include "gameObject.h"
#include "game.h"
#include "central.h"



void GameObject::Tick()
{
	if (spriteRenderer != nullptr)
	{
		spriteRenderer->Draw();
	}

	DrawOrigin();
	
}


void GameObject::DrawOrigin()
{
	surface->Box(x - 1, y + 1, x + 1, y - 1, 0xFF0000);
}

