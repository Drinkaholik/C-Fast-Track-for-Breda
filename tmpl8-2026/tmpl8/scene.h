#pragma once

// Abstract class
// The scene is a container for all gameObjects in a given level
// It initializes by loading all start prefabs, such as player, enemies, etc

#include <memory>
#include "gameObject.h"
#include "playerPrefab.h"

class CollisionSystem;

// Abstract class
// Acts as a container for all gameObjects & logic in a given scene

class Scene
{
public:

	virtual void LoadScene(bool debug) = 0;  // Calls Start() on all scene objects
	void UnloadScene(); // The vector of smart ptrs is destroyed when this scene is, so theres no need for manual mem management right?
	GameObject* AddObject(std::unique_ptr<GameObject>& go);

	// Big issue with this: it'll break the pointers I create in AddObject. How tf do I fix that?
	// I think i wont add any objects during Tick()
	void Merge(); // Merges the object buffer into sceneObjects
	
	void Tick(); // Runs per-frame logic for all scene objects
	
	bool debug; // Sets debug state of all gameObjects
	

protected:

	// Every scene needs a camera and a player, so they get their own pointers for easier access
	GameObject* oCamera;
	GameObject* oPlayer;

	std::vector<std::unique_ptr<GameObject>> sceneObjects; // Objects spawned into the scene
	// If the sceneObjects vector is owning, then if an enemy deletes itself when its HP reaches 0 I'll get a double-free error
	// on scene unload. So objects need to be able to remove themselves from sceneObjects in their destructor

	std::vector<std::unique_ptr<GameObject>> objectBuffer; // Necessary so that I can cleanly spawn in new objects without resizing sceneObjects while its being iterated over

	int objectCount; // Number of objects loaded into scene - do i need this for anything? maybe just good for debugging

};

