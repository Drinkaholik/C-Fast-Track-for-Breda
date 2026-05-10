#include "sceneManager.h"


void SceneManager::ChangeScene(Scene scene)
{
	if (currentScene != nullptr) 

}

Scene* SceneManager::GetScene()
{
	return currentScene.get();
}
