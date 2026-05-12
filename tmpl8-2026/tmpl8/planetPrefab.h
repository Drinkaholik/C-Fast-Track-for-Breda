#pragma once

#include "surface.h"
#include "template.h"
#include <memory>




class GameObject;



struct PlanetPrefab
{
	// No velocity, debug/no debug
	std::unique_ptr<GameObject> Load(Tmpl8::vec2 pos, Tmpl8::Sprite* spr, float mass);
	std::unique_ptr<GameObject> Load(Tmpl8::vec2 pos, Tmpl8::Sprite* spr, float mass, bool debug);


	// Velocity, debug/no debug
	std::unique_ptr<GameObject> Load(Tmpl8::vec2 pos, Tmpl8::Sprite* spr, float mass, Tmpl8::vec2 vel);
	std::unique_ptr<GameObject> Load(Tmpl8::vec2 pos, Tmpl8::Sprite* spr, float mass, Tmpl8::vec2 vel, bool debug);

};

