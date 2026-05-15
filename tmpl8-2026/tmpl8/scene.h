#pragma once

// Abstract class
// The scene is a container for all gameObjects in a given level
// It initializes by loading all start prefabs, such as player, enemies, etc


#include "gameObject.h"
#include "sceneData.h"

#include "damageSystem.h"
#include "collisionSystem.h"
#include "renderSystem.h"
#include "scoreSystem.h"

#include <memory>

class CollisionSystem;

// Abstract class
// Acts as a container for all gameObjects & logic in a given scene

class Scene
{
public:

	Scene(SceneData* data);

	void LoadScene();  // Calls Start() on all scene objects
	void UnloadScene(); // The vector of smart ptrs is destroyed when this scene is, so theres no need for manual mem management right?
	void ResetScene();

	void Tick(); // Runs per-frame logic for all scene objects


	GameObject* AddObject(std::unique_ptr<GameObject>& go, bool runStart); // Used by spawners to push to sceneObjects and run Start()
	
	void SetPlayer(GameObject* player) { oPlayer = player; };
	void SetCamera(GameObject* camera) { oCamera = camera; };


	// Getters
	std::vector<std::unique_ptr<GameObject>>* GetSceneObjects() { return &sceneObjects; };

	GameObject* GetPlayer() { return oPlayer; };
	GameObject* GetCamera() { return oCamera; };

	RenderSystem* GetRenderSystem() { return renderSystem.get(); }
	CollisionSystem* GetCollisionSystem() { return collisionSystem.get(); };
	DamageSystem* GetDamageSystem() { return damageSystem.get(); }
	ScoreSystem* GetScoreSystem() { return scoreSystem.get(); }

	void SetDebug(bool db);
	bool setReload = false; // Flags the scene for reloading

	// Finds the first component by type in the scene and returns it
	// Need this to resolve some race conditions without the scene having a pointer to the obj
	template<typename T> T* FindFirstComponent()
	{
		for (auto& go : sceneObjects)
		{
			for (auto& comp : go->GetComponents())
			{
				T* ptr = dynamic_cast<T*>(comp.get());
				if (ptr != nullptr) return ptr;
			}
		}
		return nullptr;
	}
	

protected:

	// Every scene needs a camera and a player, so they get their own pointers for easier access
	// What about menu scene?
	GameObject* oCamera = nullptr;
	GameObject* oPlayer = nullptr;

	std::unique_ptr<RenderSystem> renderSystem = std::make_unique<RenderSystem>(10);
	std::unique_ptr<CollisionSystem> collisionSystem = std::make_unique<CollisionSystem>();
	std::unique_ptr<DamageSystem> damageSystem = std::make_unique<DamageSystem>();
	std::unique_ptr<ScoreSystem> scoreSystem = std::make_unique<ScoreSystem>();

	SceneData* sceneData; // Owned by sceneFactory
	

	std::vector<std::unique_ptr<GameObject>> sceneObjects; // Objects spawned into the scene

	int objectCount; // Number of objects loaded into scene - do i need this for anything? maybe just good for debugging

	bool debug = false; // Sets debug state of all gameObjects
	

};

