#pragma once

//#include "baseComponents.h"

#include <vector>
#include <memory>

struct Component;

// Has a world-space position
// Can hold pointers to components like colliders and spriterenderers


class GameObject
{

public:

	// Position
	float x, y;

	bool debug = false; // Whether to draw origin, collider rect, etc



	// Turns out that template functions need to always be defined in the header??
	// Variadic template, still don't understand everything about it
	// For this I need to learn about:
	// 1. Perfect forwarding
	// 2. How recursion relates to variadic templates
	// 3. How the placement of ellipses and brackets changes the behaviour
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


	virtual void Tick(); // Per-frame logic


	// Constructors
	GameObject(float xSpawn, float ySpawn);

	GameObject(float xSpawn, float ySpawn, bool debug);



private:

	std::vector<std::unique_ptr<Component>> components;

	void DrawOrigin(); // To test whether origin is correctly at centre of sprite, instead of top-left



};

