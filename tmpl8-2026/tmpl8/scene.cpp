#include "scene.h"
#include "sceneData.h"

using namespace std;

Scene::Scene(unique_ptr<SceneData> data)
{
	// Instantiates all sceneData objects and pushes them to sceneObjects vector
	data->LoadObjects(&sceneObjects);
}

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
