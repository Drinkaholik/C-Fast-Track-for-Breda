#include "gravBody.h"

#include "gameObject.h"
#include "gravitySystem.h"
#include "utils.h"

#include <cmath>
#include <memory>
#include <iostream>
#include <string>

using namespace std;
using namespace Tmpl8;


GravBody::GravBody(float m, Collider* collider) : mass(m), collider(collider)
{
};

GravBody::GravBody(float m, vec2 vel, Collider* collider)
	: mass(m), vel(vel), collider(collider) {
};


float GravBody::gravConstant = 1.0f;


void GravBody::Tick()
{
	Component::Tick();

	for (const auto& body : GravitySystem::bodies)
	{
		GravMove(body);
	}
	
}


// Moves self based on gravitational attraction of other bodies
void GravBody::GravMove(GravBody* body)
{
	if (body == this) return; // Prevent attraction to self - causes divide by 0 error

	auto* otherGO = body->gameObject;
	auto* otherCol = otherGO->GetComponent<Collider>();

	float& x = gameObject->pos.x;
	float& y = gameObject->pos.y;

	float oX = otherGO->pos.x;
	float oY = otherGO->pos.y;

	
	float distance = utils::distance(x, y, oX, oY);
	float xDistance = (oX - x);
	float yDistance = (oY - x);

	float force = (gravConstant * mass * body->mass) / (distance * distance);

	if (collider->CollideAt(vec2(x, y), otherCol)) force = 0; // Stop gravity from building up endlessly during a collision

	float xRatio = xDistance / distance;
	float yRatio = yDistance / distance;

	float xForce = xRatio * force;
	float yForce = yRatio * force;


	// Lets do some trig to decompose the forces
	// Force is our hypotenuse, and xForce / yForce are the opposite and adjacent sides

	vel.x += xForce / mass * Central::deltaTime;
	vel.y += yForce / mass * Central::deltaTime;

	/*cout << "myPosition: " << to_string(x) << " , " << to_string(y) << endl
		<< "theirPosition: " << to_string(oX) << " , " << to_string(oY) << endl;*/

	/*cout << "Force: " << to_string(xForce) << " , " << to_string(yForce) << endl;*/

	collider->MoveAndCollide(vel);


}