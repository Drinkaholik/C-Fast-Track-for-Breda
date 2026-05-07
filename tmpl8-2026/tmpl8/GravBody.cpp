#include "gravBody.h"

#include "gameObject.h"
#include "central.h"

#include <cmath>
#include <memory>


GravBody::GravBody(int m, Collider* collider) : mass(m), collider(collider)
{
};


void GravBody::Tick()
{
	Component::Tick();

	for (const auto& body : Central::gravBodies)
	{
		Gravity(*body.get());
	}
	
}


// Moves self based on gravitational attraction of other bodies
void GravBody::Gravity(GameObject& body)
{

	GravBody* gravBody = body.GetComponent<GravBody>();

	float& x = gameObject->x;
	float& y = gameObject->y;

	float oX = body.x;
	float oY = body.y;

	float xDistance = (x - oX);
	float yDistance = (y - oY);

	//float distance = sqrt((xDistance * xDistance) + (yDistance * yDistance)); // pythagors

	float xForce = (mass * gravBody->mass) / xDistance;
	float yForce = (mass * gravBody->mass) / yDistance;

	// how do I decompose the force into its constituent x and y?

	collider->MoveAndCollide(xForce, yForce, Central::spawnedObjects);


}