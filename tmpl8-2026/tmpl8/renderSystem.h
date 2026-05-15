#pragma once


#include <array>
#include <unordered_set>
#include <memory>

class SpriteRenderer;

class RenderSystem
{
public:

	RenderSystem(int layerCount);

	void Render();

	void Register(int layer, SpriteRenderer* spr);
	void Deregister(int layer, SpriteRenderer* spr);


private:

	// This looks insane
	std::vector<std::unique_ptr<std::unordered_set<SpriteRenderer*>>> layers;

	int layerCount;

};

