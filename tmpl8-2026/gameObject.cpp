#include "gameObject.h"
#include "central.h"
#include "baseComponents.h"

using namespace std;


GameObject::GameObject(float xSpawn, float ySpawn)
	: x(xSpawn), y(ySpawn)
{
};

GameObject::GameObject(float xSpawn, float ySpawn, bool debug)
	: x(xSpawn), y(ySpawn), debug(debug)
{
};


void GameObject::Tick()
{
	for (const auto& component : components)
	{
		
	}
	
}







void GameObject::DrawOrigin(bool debug)
{
	if (!debug) return;
	Central::surface->Box(x - 1, y + 1, x + 1, y - 1, 0xFF0000);
}

