#include "camera.h"
#include "gameObject.h"

using namespace std;

Camera::Camera(GameObject* target) : target(target) {};

void Camera::Start()
{
	Central::camera = this->gameObject;
}

void Camera::Tick()
{
	FollowTarget();
}

void Camera::SetTarget(GameObject* go)
{
	target = go;

}

void Camera::FollowTarget()
{

	gameObject->x = target->x - Central::screenWidth / 2;
	gameObject->y = target->y - Central::screenHeight / 2;

}