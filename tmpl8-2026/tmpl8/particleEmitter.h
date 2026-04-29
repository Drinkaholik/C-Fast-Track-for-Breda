#pragma once
#include "gameObject.h"
#include "template.h"
#include "surface.h"

#include <vector>


using namespace std;

class ParticleEmitter : public GameObject
{

	int particleCount;

	struct Particle
	{
		float x;
		float y;
		float vx;
		float vy;
		Pixel colour;
	};

	virtual void Test() = 0;

	vector<Particle> particles;
	

	void DrawParticles();

public:
	ParticleEmitter(Surface* screen, Sprite* spr, float xPos, float yPos)
		: GameObject(screen, spr, xPos, yPos)
	{


	};


};

