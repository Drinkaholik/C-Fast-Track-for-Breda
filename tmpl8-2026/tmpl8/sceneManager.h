#pragma once

#include "scene.h"
#include <memory>

// Holds a list of all scenes
// Handles all scene logic (loading, tick, unloading)

class SceneManager
{

public:

	void ChangeScene(Scene scene); // Loads new scene, and unloads previous one (if it exists)

	Scene* GetScene();


private:

	std::unique_ptr<Scene> currentScene;




};

