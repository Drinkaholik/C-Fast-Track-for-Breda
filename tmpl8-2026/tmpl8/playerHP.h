#pragma once
#include "baseComponents.h"



class PlayerHP : public Component
{

private:

	int hp;
	int maxHP;


public:

	PlayerHP(int maxHP) : maxHP(maxHP), hp(maxHP) {};


	// These functions are small enough to keep in the header
	// Should give better performance since it'll stop cache misses
	void SetHP(int value)
	{
		value = Clamp(hp, 0, maxHP);

		hp = value;
	}

	void IncreaseHP(int value) {hp += value;};

	void DecreaseHP(int value) {hp -= value;};



	int GetHP() {return hp;}
	



};

