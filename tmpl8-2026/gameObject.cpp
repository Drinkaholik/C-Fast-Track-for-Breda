#include "gameObject.h"
#include "central.h"



void GameObject::Tick()
{
	for (const auto& component : components)
	{
		
	}
	
}


template <typename T, typename... Args>
T& addComponent(Args&&... args) {
	auto comp = std::make_unique<T>(std::forward<Args>(args)...);
	comp->owner = this;
	T& ref = *comp;
	//components.push_back(std::move(comp));
	return ref;
}


template <typename T> T* GameObject::GetComponent()
{
	for (const auto& component : components) // Loops through components list by reference
	{
		T* ptr = dynamic_cast<T*>(component.get());
		if (ptr) return ptr;
	}
	return nullptr;
}


void GameObject::DrawOrigin(bool debug)
{
	if (!debug) return;
	Central::surface->Box(x - 1, y + 1, x + 1, y - 1, 0xFF0000);
}

