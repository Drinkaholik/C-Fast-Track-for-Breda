#pragma once
#include "baseComponents.h"

#include "template.h"

class FPSCounter : public Component
{

public:
	void Tick() override;

private:

	Tmpl8::vec2 screenPos = Tmpl8::vec2(30.0f, 30.0f);
	int scaleX = 5;
	int scaleY = 5;
	int colour = 0xFFFFFF;

	int smoothedFPS = 1;
	float smoothing = 100; // Higher means smoother FPS, but less precise

	void ShowFPS();


};

