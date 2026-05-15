#include "spriteFactory.h"


using namespace Tmpl8;
using namespace std;

// Init spriteInfo instances here
SpriteFactory::SpriteInfo ufo = { "assets/ufo.png", 3 };
SpriteFactory::SpriteInfo missile = { "assets/missile.png", 8 };
SpriteFactory::SpriteInfo cow = { "assets/cow.png", 1 };
SpriteFactory::SpriteInfo house = { "assets/house.png", 1 };


// Sprites are shared across gameObjects. Might become an issue if I wanna do flashing 
unordered_map<string, SpriteFactory::SpriteInfo*> SpriteFactory::sprites =
{
	{ "ufo", &ufo },
	{ "missile", &missile },
	{ "cow", &cow },
	{ "house", &house },
	
	
	
};

Sprite sprite = Sprite(new Surface("assets/house.png"), 1);




unique_ptr<Sprite> SpriteFactory::BuildSprite(string spriteName)
{
	auto info = sprites[spriteName];

	return make_unique<Sprite>(new Surface(info->address.c_str()), info->frameCount);
}

