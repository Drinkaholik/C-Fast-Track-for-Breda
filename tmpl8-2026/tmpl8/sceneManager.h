#pragma once

#include "scene.h"
#include "mainScene.h"
#include <memory>
#include <unordered_map>

// Holds a list of all scenes
// Handles all scene logic (loading, tick, unloading)

struct SceneData;
//struct MainSceneData;

class SceneManager
{

public:

	SceneManager();

	std::unordered_map<int, std::unique_ptr<Scene>> sceneList;

	void LoadScene(int sceneID); // Loads new scene, and unloads previous one (if it exists)

	Scene* GetScene();


private:

	// Holds all the gameObjects a level starts with
	// Lets me have just a single scene class with different implementations, instead of a different class for each scene

	void InitMap();

	Scene* currentScene;

	


};

