#include "gameObject.h"
#include "game.h"
#include "locator.h"



void GameObject::Tick()
{
	Draw(transform.x, transform.y);
}

void GameObject::Draw(float x, float y)
{
	sprite->Draw(surface, x, y);

};

