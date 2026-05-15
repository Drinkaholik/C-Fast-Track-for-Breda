#pragma once
#include "baseComponents.h"

//#include "scene.h"


class PlayerHP : public Component
{
public:

	void Start() override;

	void TakeDamage();

	void SetHP(int value);
	int GetHP();

	

	PlayerHP(Scene* scene, int maxHP);

private:

	int hp;
	int maxHP;

	SpriteRenderer* spriteRenderer;
	
};

