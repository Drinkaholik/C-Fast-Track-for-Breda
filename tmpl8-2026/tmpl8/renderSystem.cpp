#include "renderSystem.h"

#include "baseComponents.h"

using namespace std;

RenderSystem::RenderSystem(int layerCount)
{
	layers.reserve(layerCount);
	for (int i = 0; i < layerCount; i++)
	{
		layers.push_back(make_unique<unordered_set<SpriteRenderer*>>());
	};

	
}


// Renders layers one after the other, ensuring layers with a higher
// index are drawn on top
void RenderSystem::Render()
{
	for (auto& layer : layers)
	{
		for (auto* rend : *layer)
		{
			if (!rend->active) return
			rend->Tick();
		}
	}
}

void RenderSystem::Register(int layer, SpriteRenderer* spr)
{
	layers[layer]->insert(spr);
}

void RenderSystem::Deregister(int layer, SpriteRenderer* spr)
{
	layers[layer]->erase(spr);
}