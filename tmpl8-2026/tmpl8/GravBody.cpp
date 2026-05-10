#include "gravBody.h"

#include "gameObject.h"
#include "central.h"
#include "utils.h"

#include <cmath>
#include <memory>
#include <iostream>
#include <string>

using namespace std;


GravBody::GravBody(float m, Collider* collider) : mass(m), collider(collider)
{
};

GravBody::GravBody(float m, float xVel, float yVel, Collider* collider)
	: mass(m), xVel(xVel), yVel(yVel), collider(collider) {
};


float GravBody::gravConstant = 1.0f;


void GravBody::Tick()
{
	Component::Tick();

	for (const auto& body : Central::gravBodies)
	{
		GravMove(body);
	}
	
}


// Moves self based on gravitational attraction of other bodies
void GravBody::GravMove(GravBody* body)
{
	if (body == this) return; // Prevent attraction to self - causes divide by 0 error

	auto* otherGO = body->gameObject;

	float& x = gameObject->x;
	float& y = gameObject->y;

	float oX = otherGO->x;
	float oY = otherGO->y;

	
	float distance = utils::distance(x, y, oX, oY);
	float xDistance = (oX - x);
	float yDistance = (oY - x);

	float force = (gravConstant * mass * body->mass) / (distance * distance);

	if (collider->CollideAt(x, y, otherGO)) force = 0; // Stop gravity from building up endlessly during a collision

	float xRatio = xDistance / distance;
	float yRatio = yDistance / distance;

	float xForce = xRatio * force;
	float yForce = yRatio * force;


	// Lets do some trig to decompose the forces
	// Force is our hypotenuse, and xForce / yForce are the opposite and adjacent sides

	xVel += xForce / mass * Central::deltaTime;
	yVel += yForce / mass * Central::deltaTime;

	/*cout << "myPosition: " << to_string(x) << " , " << to_string(y) << endl
		<< "theirPosition: " << to_string(oX) << " , " << to_string(oY) << endl;*/

	/*cout << "Force: " << to_string(xForce) << " , " << to_string(yForce) << endl;*/

	collider->MoveAndCollide(xVel, yVel, Central::spawnedObjects);


}