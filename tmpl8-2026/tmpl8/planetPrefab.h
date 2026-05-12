#pragma once

#include "surface.h"
#include <memory>




class GameObject;



struct PlanetPrefab
{
	// No velocity, debug/no debug
	std::unique_ptr<GameObject> Load(float xPos, float yPos, Tmpl8::Sprite* spr, float mass);
	std::unique_ptr<GameObject> Load(float xPos, float yPos, Tmpl8::Sprite* spr, float mass, bool debug);


	// Velocity, debug/no debug
	std::unique_ptr<GameObject> Load(float xPos, float yPos, Tmpl8::Sprite* spr, float mass, float xVel, float yVel);
	std::unique_ptr<GameObject> Load(float xPos, float yPos, Tmpl8::Sprite* spr, float mass, float xVel, float yVel, bool debug);

};

