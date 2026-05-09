#pragma once


// The scene is a container for all gameObjects in a given level
// It initializes by loading all start prefabs, such as player, minimap, etc

#include <memory>
#include "gameObject.h"
#include "playerPrefab.h"

class Scene
{


public:

	std::shared_ptr<GameObject> sceneObjects;

	// Unloads all scene objects
	~Scene();

private:

	void LoadScene();

	PlayerPrefab playerPrefab;

	int objectCount; // Number of objects loaded into scene


};

