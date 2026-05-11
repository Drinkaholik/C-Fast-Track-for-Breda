#pragma once

// Abstract class
// The scene is a container for all gameObjects in a given level
// It initializes by loading all start prefabs, such as player, enemies, etc

#include <memory>
#include "gameObject.h"
#include "playerPrefab.h"

struct SceneData;
struct CollisionSystem;

// Acts as a container for all gameObjects & logic in a given scene

class Scene
{
public:

	virtual void LoadScene() = 0; // Calls Start() on all scene objects
	void UnloadScene(); // The vector of smart ptrs is destroyed when this scene is, so theres no need for manual mem management right?
	
	void Tick(); // Runs per-frame logic for all scene objects
	
	

protected:

	// Every scene needs a camera and a player, so they get their own pointers for easier access
	GameObject* oCamera;
	GameObject* oPlayer;

	std::vector<std::unique_ptr<GameObject>> sceneObjects; // Objects spawned into the scene
	// If the sceneObjects vector is owning, then if an enemy deletes itself when its HP reaches 0 I'll get a double-free error
	// on scene unload. Wouldn't it make more sense to use raw pointers, and then in unload() loop through vector and check for nullptr
	// before deleting the object?

	//int objectCount; // Number of objects loaded into scene - do i need this for anything? maybe just good for debugging

};

