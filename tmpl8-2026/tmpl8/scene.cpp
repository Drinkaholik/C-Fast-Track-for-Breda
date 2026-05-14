#include "scene.h"
#include "baseComponents.h"
#include "collisionSystem.h"

using namespace std;


void Scene::Tick() // Runs tick logic on all scene objects
{
	for (auto& obj: sceneObjects)
	{
		obj->Tick();
	}
}

void Scene::UnloadScene() {}; // Not sure what to put in here yet. savedata maybe but im not doing that

GameObject* Scene::AddObject(std::unique_ptr<GameObject>& go)
{
	objectCount++;

	auto& ref = sceneObjects.emplace_back(move(go));
	ref->Start();
	ref->debug = debug;

	return ref.get();
}

void Scene::SetDebug(bool db)
{
	debug = db;
	for (auto& obj : sceneObjects) // This is probably pretty expensive? Calling getComponent() and deregister()
	{
		obj->debug = debug;
	}
}
