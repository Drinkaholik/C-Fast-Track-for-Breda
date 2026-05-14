#pragma once

#include "gameObject.h"
#include "baseComponents.h"
#include "template.h"
#include <memory>


// How can I use a variadic template to make a generic prefab?
// Do I need an overload for each additional component it needs to add? 
// It needs to know the components to add with AddComponent<>(), as well as
// the arguments to pass to each component constructor



class Prefab
{

	// Nah this doesnt work at all	

	// Single component go
	template <typename... Args>
	GameObject* Load(Tmpl8::vec2 pos, Component c, Args&&... args)
	{
		auto go = std::make_unique<GameObject>(pos);

		go->AddComponent<Component>(std::forward<Args>(args...));
	}


	// 2-component go
	template <typename... Args>
	GameObject* Load(Tmpl8::vec2 pos, Component c1, Args&&... args1, Component c2, Args&&... args2)
	{
		auto go = std::make_unique<GameObject>(pos);

		go->AddComponent<Component>(std::forward<Args>(args...));
	}
};

