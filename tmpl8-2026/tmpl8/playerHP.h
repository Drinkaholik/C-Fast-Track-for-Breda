#pragma once
#include "baseComponents.h"



class PlayerHP : public Component
{

public:

	PlayerHP(int maxHP) : maxHP(maxHP), hp(maxHP) {};

	void SetHP(int hp);
	int GetHP();
	

private:

	int hp;
	int maxHP;


};

