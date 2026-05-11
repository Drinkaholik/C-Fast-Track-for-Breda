#pragma once

#include "surface.h"
#include <memory>




class GameObject;



struct PlanetPrefab
{
	std::unique_ptr<GameObject> Load(float xPos, float yPos, Tmpl8::Sprite* spr, float mass);
	std::unique_ptr<GameObject> Load(float xPos, float yPos, Tmpl8::Sprite* spr, float mass, float xVel, float yVel);

};

