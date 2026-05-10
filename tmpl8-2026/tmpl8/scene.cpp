#include "scene.h"


Scene::~Scene() = default;

void Scene::LoadScene()
{
	for (auto& obj : sceneObjects)
	{
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
}
