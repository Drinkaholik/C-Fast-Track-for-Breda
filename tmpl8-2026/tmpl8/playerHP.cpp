#include "playerHP.h"


void PlayerHP::SetHP(int value)
{
	value = Clamp(hp, 0, maxHP);

	hp = value;

}

int PlayerHP::GetHP()
{
	return hp;
}
