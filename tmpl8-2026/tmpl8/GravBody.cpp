#include "gravBody.h"

#include "gameObject.h"
#include "central.h"

#include <cmath>
#include <memory>
#include <iostream>
#include <string>

using namespace std;


GravBody::GravBody(int m, Collider* collider) : mass(m), collider(collider)
{
};


void GravBody::Tick()
{
	Component::Tick();

	for (const auto& body : Central::gravBodies)
	{
		Gravity(body.get());
	}
	
}


// Moves self based on gravitational attraction of other bodies
void GravBody::Gravity(GameObject* body)
{
	if (body == this->gameObject) return;

	GravBody* gravBody = body->GetComponent<GravBody>();

	float& x = gameObject->x;
	float& y = gameObject->y;

	float oX = body->x;
	float oY = body->y;

	cout << "myPosition: " << to_string(x) << " , " << to_string(y) << endl
		<< "theirPosition: " << to_string(oX) << " , " << to_string(oY) << endl;

	float xDistance = (x - oX);
	float yDistance = (y - oY);

	//float distance = sqrt((xDistance * xDistance) + (yDistance * yDistance)); // pythagors

	float xForce = (mass * gravBody->mass) / xDistance;
	float yForce = (mass * gravBody->mass) / yDistance;

	// how do I decompose the force into its constituent x and y?

	//x -= xForce * Central::deltaTime;
	//y -= yForce * Central::deltaTime;
	cout << "Position: " << to_string(x) << " , " << to_string(y) << endl
		<< "Force: " << to_string(xForce) << to_string(yForce) << endl;

	collider->MoveAndCollide(xForce, yForce, Central::spawnedObjects);


}