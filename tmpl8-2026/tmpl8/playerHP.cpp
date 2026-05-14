#include "playerHP.h"

#include "scene.h"
#include "spriteList.h"


using namespace Tmpl8;
using namespace std;

// Structors
PlayerHP::PlayerHP(Scene* scene, int maxHP) : maxHP(maxHP), hp(maxHP)
{
	scene->GetDamageSystem()->SetPlayerHP(this);
};


void PlayerHP::Start()
{
	spriteRenderer = gameObject->GetComponent<SpriteRenderer>();
}


void PlayerHP::SetHP(int value)
{
	value = Clamp(hp, 0, maxHP);

	hp = value;
}

void PlayerHP::TakeDamage()
{
	hp--;

	if (hp == 2) // Bit hacky
	{
		spriteRenderer->ChangeSprite(SpriteList::sprites["ufo_2hp"]);
	}
	else if (hp == 1)
	{
		spriteRenderer->ChangeSprite(SpriteList::sprites["ufo_1hp"]);
	}
}


int PlayerHP::GetHP() 
{ 
	return hp; 
}