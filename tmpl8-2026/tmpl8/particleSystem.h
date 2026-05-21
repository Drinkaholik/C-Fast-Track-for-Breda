#pragma once

#include "central.h"
#include "surface.h"
#include <vector>





class ParticleSystem
{

public:

	ParticleSystem()
	{
		particles.reserve(1024);
	}

	void Start()
	{
		buffer = Central::surface->GetBuffer();
	}


	void AddParticle(int xPos, int yPos)
	{
		particles.push_back(Particle(xPos, yPos));
	}


	void MoveParticles()
	{
		for (auto p : particles)
		{
			if (!p.canMove) continue;

			for (auto& dir : directions)
			{

			}


		}
	}

	void DrawParticles()
	{
		for (auto p : particles)
		{
			Central::surface->Plot(p.x, p.y, 0xFFFFFF);
			//buffer[PointToBuffer(p.x, p.y)] = 0xFFFFFF;
		}
	}


private:
	struct Particle
	{
		int x, y;
		bool canMove;

		Particle() : x(0), y(0), canMove(true) {};
		Particle(int xPos, int yPos) : x(xPos), y(yPos), canMove(true) {};

	};

	struct Direction
	{
		int x, y;
	};

	Direction directions[8] =
	{
		{0, -1}, // Top
		{1, -1}, // Top-right
		{1, 0}, // Right
		{1, 1}, // Bottom-right
		{0, 1}, // Bottom
		{-1, 1}, // Bottom-left
		{-1, 0}, // Left
		{-1, -1}, // Top-left
	};

	struct Point
	{
		int x, y;
		bool filled;
	};

	int PointToBuffer(int x, int y)
	{
		auto width = Central::surface->GetWidth();
		auto height = Central::surface->GetHeight();
		if (x < 0) x = 0;
		if (y < 0) y = 0;
		if (x > width) x = width;
		if (y > height) y = height;
		return x + y * Central::surface->GetPitch();
	};

	std::vector<Particle> particles;
	Tmpl8::Pixel* buffer;

};

