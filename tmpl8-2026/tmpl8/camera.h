#pragma once
#include "baseComponents.h"

#include <memory>

class GameObject;


struct Camera : public Component
{

	Camera(GameObject* target);

	/*struct Rect
	{
		int x1, y1;
		int x1, y2;
	};*/

	void Start() override;
	void Tick() override;

	void SetTarget(GameObject* go);


private:

	GameObject* target;

	void FollowTarget();



};

