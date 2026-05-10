#pragma once

// Abstract class
// The scene is a container for all gameObjects in a given level
// It initializes by loading all start prefabs, such as player, enemies, etc

#include <memory>
#include "gameObject.h"
#include "playerPrefab.h"

struct SceneData;

// Acts as a container for all gameObjects & logic in a given scene

class Scene
{
public:

	Scene(std::unique_ptr<SceneData> data);

	void LoadScene(); // Calls Start() on all scene objects
	void Tick(); // Runs per-frame logic for all scene objects
	void UnloadScene(); // The vector of shared ptrs is destroyed when this scene is, so theres no need for manual mem management right?


private:

	// Every scene needs a camera and a player, so they get their own pointers for easier access
	std::shared_ptr<GameObject> oCamera;
	std::shared_ptr<GameObject> oPlayer;

	std::vector<std::shared_ptr<GameObject>> sceneObjects; // Objects spawned into the scene
	// If the sceneObjects vector is owning, then if an enemy deletes itself when its HP reaches 0 I'll get a double-free error
	// on scene unload. Wouldn't it make more sense to use raw pointers, and then in unload() loop through vector and check for nullptr
	// before deleting the object?

	//int objectCount; // Number of objects loaded into scene - do i need this for anything? maybe just good for debugging

};

