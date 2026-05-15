#include "gameObject.h"

#include "central.h"
#include "baseComponents.h"
#include "template.h"

using namespace std;
using namespace Tmpl8;




void GameObject::Start()
{
	for (const auto& component : components)
	{
		component->Start();
	}
}

void GameObject::Tick()
{
	if (!active) return;
	for (const auto& component : components)
	{
		component->Tick();
	}

	DrawOrigin();
}


vector<unique_ptr<Component>>& GameObject::GetComponents()
{
	auto& ref = components;
	return ref;
}


void GameObject::SetActive(bool isActive)
{
	active = isActive;

	for (auto& c : components)
	{
		c->active = active;
	}
}



void GameObject::DrawOrigin()
{
	if (!debug) return;

	vec2 offset = Central::camera->pos;
	vec2 screenPos = pos - offset;

	Central::surface->Box(
		(int)round(screenPos.x - 2), // Rounding keeps box size consistent - truncation causes jitter
		(int)round(screenPos.y - 2),
		(int)round(screenPos.x + 2),
		(int)round(screenPos.y + 2),
		0xFF0000);
}

