#include "playerHP.h"

#include "scene.h"
#include "spriteFactory.h"


using namespace Tmpl8;
using namespace std;

// Structors
PlayerHP::PlayerHP(Scene* scene, int maxHP) : scene(scene), maxHP(maxHP), hp(maxHP)
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

	if (hp < 1)
	{
		Die();
		return;
	}
	spriteRenderer->SetFrame(hp - 1);
}



int PlayerHP::GetHP() 
{ 
	return hp; 
}


void PlayerHP::Die()
{
	scene->setReload = true;

}