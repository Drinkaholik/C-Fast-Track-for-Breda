#include "scene.h"
#include "baseComponents.h"
#include "collisionSystem.h"

using namespace std;



void Scene::LoadScene(bool debug)
{
	for (auto& obj : sceneObjects)
	{
		// Add any colliders to vector
		auto* col = obj->GetComponent<Collider>();
		if (col != nullptr) CollisionSystem::Register(col);
		obj->debug = debug;

		obj->Start();
	}
}

void Scene::Tick() // Runs tick logic on all scene objects
{
	for (auto& obj: sceneObjects)
	{
		obj->Tick();
	}
}

void Scene::UnloadScene()
{
	for (auto& obj : sceneObjects) // This is probably pretty expensive? Calling getComponent() and deregister()
	{
		// Remove any colliders from CollisionSystem::colliders
		auto* col = obj->GetComponent<Collider>();
		if (col != nullptr) CollisionSystem::Deregister(col);

	}
}
