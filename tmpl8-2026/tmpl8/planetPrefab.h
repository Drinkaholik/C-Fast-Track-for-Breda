#pragma once

#include "surface.h"
#include <memory>




class GameObject;



struct PlanetPrefab
{
	std::shared_ptr<GameObject> Load(float xPos, float yPos, Sprite* spr, float mass);
	std::shared_ptr<GameObject> Load(float xPos, float yPos, Sprite* spr, float mass, float xVel, float yVel);

};

