#pragma once

#include "surface.h"

#include <unordered_map>
#include <string>


// Holds a map of all sprites to be used in game
// Allows me to call them by name instead of location
struct SpriteList
{
	// Key is sprite name, e.g: "ship1"
	// Value is a sprite pointer
	static std::unordered_map<std::string, Tmpl8::Sprite*> sprites;

};

