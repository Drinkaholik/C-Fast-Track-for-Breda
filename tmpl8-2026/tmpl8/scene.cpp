#include "scene.h"

#include "baseComponents.h"
#include "collisionSystem.h"
#include "sceneData.h"
#include "mainSceneData.h"
#include "sceneFactory.h"

using namespace std;


Scene::Scene(SceneData* data) : sceneData(data) {};


void Scene::LoadScene()
{

	sceneData->LoadScene(this);

	for (auto& go : sceneObjects)
	{
		go->Start();
	}
}

void Scene::Tick() // Runs tick logic on all scene objects
{
	for (auto& obj: sceneObjects)
	{
		obj->Tick();
	}

	renderSystem->Render();
}

void Scene::UnloadScene() {}; // Not sure what to put in here yet. savedata maybe but im not doing that


GameObject* Scene::AddObject(std::unique_ptr<GameObject>& go, bool runStart)
{
	objectCount++;

	auto& ref = sceneObjects.emplace_back(move(go));
	if (runStart) ref->Start();
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
