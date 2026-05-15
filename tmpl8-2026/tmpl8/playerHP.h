#pragma once
#include "baseComponents.h"

class Scene;

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

	void Die();

	SpriteRenderer* spriteRenderer;
	Scene* scene;
	
};

