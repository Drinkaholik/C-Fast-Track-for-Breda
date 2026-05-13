#include "sceneManager.h"



using namespace std;

SceneManager::SceneManager()
{
	InitMap();
}

void SceneManager::InitMap()
{
	sceneList[0] = std::make_unique<MainScene>();
}


// Loads with debug info
void SceneManager::LoadScene(int sceneID, bool debug)
{
	if (currentScene != nullptr)
	{
		currentScene->UnloadScene();
	}
	currentScene = sceneList[sceneID].get();
	currentScene->LoadScene(debug);
}

Scene* SceneManager::GetScene()
{
	return currentScene;
}
