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

	void LoadScene(int sceneID, bool debug); // Loads new scene, and unloads previous one (if it exists)

	Scene* GetScene();


private:

	void InitMap(); // trying to init map of unique ptrs in header was causing issues - copy constructor being invoked?

	Scene* currentScene = nullptr;

	


};

