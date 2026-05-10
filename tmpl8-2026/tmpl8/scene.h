#pragma once

// Abstract class
// The scene is a container for all gameObjects in a given level
// It initializes by loading all start prefabs, such as player, enemies, etc

#include <memory>
#include "gameObject.h"
#include "playerPrefab.h"

// Abstract class
// Acts as a container for all gameObjects & logic in a given scene

class Scene
{
public:

	virtual void LoadScene(); // Calls Start() on all scene objects
	virtual void Tick(); // Runs per-frame logic for all scene objects
	virtual void UnloadScene(); // The vector of shared ptrs is destroyed when this scene is, so theres no need for manual mem management right?

	// Unloads all scene objects
	virtual ~Scene() = 0;

protected:

	// Every scene needs a camera and a player, so they get their own pointers
	shared_ptr<GameObject> sceneCamera;
	shared_ptr<GameObject> player;

	std::vector<std::shared_ptr<GameObject>> sceneObjects; // Objects spawned into the scene
	int objectCount; // Number of objects loaded into scene - do i need this for anything? maybe just good for debugging

};

