#pragma once
#include <unordered_map>
#include <string>

// Holds a map of all sprites to be used in game
// Allows me to call them by name instead of location
struct SpriteList
{
	// Key is sprite name, e.g: "ship1"
	// Value is sprite location, e.g: "assets/aagun.tga"
	static std::unordered_map<std::string, std::string> sprites;

};

