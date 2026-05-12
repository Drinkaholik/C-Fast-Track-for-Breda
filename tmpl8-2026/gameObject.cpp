#include "gameObject.h"
#include "central.h"
#include "baseComponents.h"

using namespace std;

// Constructors //
GameObject::GameObject(float xSpawn, float ySpawn)
	: x(xSpawn), y(ySpawn)
{};

GameObject::GameObject(float xSpawn, float ySpawn, bool debug)
	: x(xSpawn), y(ySpawn), debug(debug) 
{};


void GameObject::Start()
{
	for (const auto& component : components)
	{
		component->Start();
	}


}

void GameObject::Tick()
{
	for (const auto& component : components)
	{
		component->Tick();
	}

	DrawOrigin();
	
}







void GameObject::DrawOrigin()
{
	if (!debug) return;

	float xOffset = Central::camera->x;
	float yOffset = Central::camera->y;

	Central::surface->Box(
		round(x - 1 - xOffset), // Rounding keeps box size consistent - would truncate otherwise
		round(y - 1 - yOffset), 
		round(x + 1 - xOffset), 
		round(y + 1 - yOffset),
		0xFF0000);
}

