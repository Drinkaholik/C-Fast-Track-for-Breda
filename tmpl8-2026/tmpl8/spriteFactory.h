#pragma once

#include "surface.h"

#include <unordered_map>
#include <string>
#include <memory>


// Holds a map of all sprites to be used in game
// Allows me to call them by name instead of location
class SpriteFactory
{
public:
	

	struct SpriteInfo
	{
		std::string address;
		int frameCount;
	};


	static std::unordered_map<std::string, SpriteInfo*> sprites;

	static std::unique_ptr<Tmpl8::Sprite> BuildSprite(std::string spriteName);


	

};



