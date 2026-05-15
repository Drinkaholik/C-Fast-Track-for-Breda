#include "sceneManager.h"

#include "sceneFactory.h"

using namespace std;



// Loads with debug info
void SceneManager::LoadScene(int sceneID, bool debug)
{

	currentScene.reset();

	currentScene = move(SceneFactory::BuildScene(sceneID));
	currentScene->LoadScene();
	currentScene->SetDebug(debug);
}

Scene* SceneManager::GetScene()
{
	return currentScene.get();
}
