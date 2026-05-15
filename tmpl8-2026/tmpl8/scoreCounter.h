#pragma once
#include "baseComponents.h"


class ScoreSystem;

class ScoreCounter : public Component
{
public:

	ScoreCounter(Scene* scene);
	
	void Tick() override;

private:

	Tmpl8::vec2 screenPos = Tmpl8::vec2(650, 850);
	int scaleX = 10;
	int scaleY = 10;
	int colour = 0xFFFF00;

	void ShowScore();

	ScoreSystem* system;

};

