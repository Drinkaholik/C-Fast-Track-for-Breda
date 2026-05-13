#pragma once
#include "baseComponents.h"
#include "template.h"

#include <memory>

class GameObject;


class Camera : public Component
{

public:
	Camera(GameObject* target);


	// Camera needs its own pos because it would otherwise necessarily be at the top right of the screen
	// and I'm basing some things off the camera transform, which should be at 
	Tmpl8::vec2 pos; 

	void Start() override;
	void Tick() override;

	void SetTarget(GameObject* go);


private:

	GameObject* target;

	void FollowTarget();



};

