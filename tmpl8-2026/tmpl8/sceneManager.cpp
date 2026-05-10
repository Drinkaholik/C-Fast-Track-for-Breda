#include "sceneManager.h"
#include "mainMenuScene.h"

using namespace std;


void SceneManager::LoadScene(int sceneID)
{
	if (currentScene != nullptr) currentScene.reset(); // Delete current scene object


	currentScene = make_shared<Scene>(sceneList[sceneID]);

}

Scene* SceneManager::GetScene()
{
	return currentScene.get();
}
