#pragma once

#include "surface.h"
#include "template.h"
#include <memory>




class GameObject;



struct PlanetPrefab
{
	// No velocity
	std::unique_ptr<GameObject> Load(Tmpl8::vec2 pos, float mass, Tmpl8::Sprite* spr);


		// Velocity
	std::unique_ptr<GameObject> Load(Tmpl8::vec2 pos, float mass, Tmpl8::vec2 vel, Tmpl8::Sprite* spr);


};

