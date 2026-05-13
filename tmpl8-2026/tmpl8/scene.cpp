#include "scene.h"
#include "baseComponents.h"
#include "collisionSystem.h"

using namespace std;



void Scene::LoadScene(bool debug)
{
	for (auto& obj : sceneObjects)
	{
		obj->Start();
		obj->debug = debug;
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
	}
}

GameObject* Scene::AddObject(std::unique_ptr<GameObject>& go)
{
	auto& ref = sceneObjects.emplace_back(move(go));
	return ref.get();
}
