#pragma once
#include "playerHP.h"


// Acts as the intermediary between missiles and the playerHP component

// Maybe also for HP UI?


class DamageSystem
{

public:

	void DealDamage()
	{
		playerHP->TakeDamage();
	}

	int GetHP()
	{
		return playerHP->GetHP();
	}

	void SetPlayerHP(PlayerHP* ptr)
	{
		playerHP = ptr;
	}

private:

	PlayerHP* playerHP;

};

