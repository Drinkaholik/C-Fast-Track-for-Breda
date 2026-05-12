#include "gameObject.h"

#include "central.h"
#include "baseComponents.h"
#include "template.h"

using namespace std;

// Constructors //
GameObject::GameObject(vec2 spawnPos)
	: pos(spawnPos)
{};

GameObject::GameObject(vec2 spawnPos, bool debug)
	: pos(spawnPos), debug(debug)
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

	vec2 offset = Central::camera->pos;
	vec2 screenPos = pos - offset;

	Central::surface->Box(
		round(screenPos.x - 1), // Rounding keeps box size consistent - truncation causes jitter
		round(screenPos.y - 1), 
		round(screenPos.x + 1), 
		round(screenPos.y + 1),
		0xFF0000);
}

