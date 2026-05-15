#pragma once

#include "scene.h"
#include <memory>
#include <unordered_map>

// Holds a list of all scenes
// Handles all scene logic (loading, tick, unloading)



class SceneManager
{

public:

	void LoadScene(int sceneID, bool debug); // Loads new scene, and unloads previous one (if it exists)

	Scene* GetScene();


private:

	std::unique_ptr<Scene> currentScene;


};

