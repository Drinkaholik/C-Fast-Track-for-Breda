#include "gameObject.h"
#include "game.h"
#include "central.h"



void GameObject::Tick()
{
	Draw(x, y);
}

void GameObject::Draw(float x, float y)
{
	// Draw from centre rather than top left
	sprite->Draw(surface, x - sprite->GetWidth()/2, y - sprite->GetHeight() / 2);

};

