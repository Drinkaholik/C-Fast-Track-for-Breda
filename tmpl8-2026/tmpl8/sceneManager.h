#pragma once

#include "scene.h"
#include <memory>
#include <unordered_map>

// Holds a list of all scenes
// Handles all scene logic (loading, tick, unloading)

struct SceneData;
struct MainSceneData;

class SceneManager
{

public:

	std::unordered_map<int, std::shared_ptr<Scene>> sceneList =
	{
		{ 0, mainMenuScene = std::make_shared<Scene>()},
		{ 1, mainScene = std::make_shared<Scene>()}
	};

	void LoadScene(int sceneID); // Loads new scene, and unloads previous one (if it exists)

	Scene* GetScene();


private:

	// Holds all the gameObjects a level starts with
	// Lets me have just a single scene class with different implementations, instead of a different class for each scene
	SceneData* sceneData; 

	std::shared_ptr<Scene> currentScene;

	std::shared_ptr<Scene> mainMenuScene;
	std::shared_ptr<Scene> mainScene;


};

