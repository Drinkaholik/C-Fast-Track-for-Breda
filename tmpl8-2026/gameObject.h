#pragma once

#include "baseComponents.h" // Forward declaration wasn't working I dont think
#include "template.h"

#include <vector>
#include <memory>


// Has a world-space position
// Can hold pointers to components like colliders and spriterenderers


class GameObject
{

public:
	
	// Position
	Tmpl8::vec2 pos;

	bool debug = false; // Whether to draw origin, collider rect, etc
	bool active = true; // Whether to run Tick() logic

	// Turns out that template functions need to always be defined in the header??
	template <typename T, typename... Args>
	T& AddComponent(Args&&... args) {
		auto comp = make_unique<T>(forward<Args>(args)...);
		comp->gameObject = this;
		T& ref = *comp;
		components.push_back(move(comp));
		return ref;
	}

	template <typename T> T* GetComponent()
	{
		for (const auto& component : components) // Loops through components list by reference
		{
			T* ptr = dynamic_cast<T*>(component.get());
			if (ptr) return ptr;
		}
		return nullptr;
	}


	// Return tells you whether component was found and removed
	template<typename T> bool RemoveComponent()
	{
		for (auto& component : components)
		{
			T* ptr = dynamic_cast<T*>(component.get());
			if (ptr)
			{
				components.erase(component); // This is the issue here, im tryna erase by value instead of index
				return true;
			}
		}
		return false;
	}




	template<typename T> bool HasComponent()
	{
		for (const auto& component : components)
		{
			T* hasComponent = dynamic_cast<T*>(component.get());

			if (hasComponent) return true;
		}
		return false;
	}

	virtual void Start();

	virtual void Tick(); // Per-frame logic


	// Constructors //
	GameObject(vec2 spawnPos) : pos(spawnPos){};

	GameObject(vec2 spawnPos, bool debug) : pos(spawnPos), debug(debug){};



private:

	std::vector<std::unique_ptr<Component>> components;


	void DrawOrigin(); // To test whether origin is correctly at centre of sprite, instead of top-left



};

