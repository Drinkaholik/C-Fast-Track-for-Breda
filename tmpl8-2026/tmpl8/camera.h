#pragma once
#include "baseComponents.h"
#include "template.h"

#include <memory>

class GameObject;


class Camera : public Component
{

public:

	
	void Start() override;
	void Tick() override;

	void SetTarget(GameObject* go);


private:

	GameObject* target = nullptr;

	void FollowTarget();

};

