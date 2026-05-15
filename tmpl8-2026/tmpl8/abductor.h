#pragma once
#include "baseComponents.h"

class Scene;
class CowManager;

class Abductor : public Component
{

public:

	void Start() override;
	void Tick() override;

	void CanAbduct(bool b) { canAbduct = b; }

	//Structors
	Abductor(Scene* scene, Collider* col) : scene(scene), col(col), game(Central::game) {};

private:

	bool canAbduct = false;

	Collider* col; // Player collider
	CowManager* cowManager = nullptr;
	Tmpl8::Game* game; // For inputs
	Scene* scene;

	void Abduct();


};

