#include "spriteList.h"


using namespace Tmpl8;
using namespace std;

// Init sprite instances here
Sprite sBall(new Surface("assets/ball.png"), 1);
Sprite sTank(new Surface("assets/aagun.tga"), 36);
Sprite sHouse(new Surface("assets/house.png"), 1);
Sprite sCow(new Surface("assets/cow.png"), 1);
Sprite sUFO_noDamage(new Surface("assets/ufo_no_damage.png"), 1);
Sprite sUFO_lightDamage(new Surface("assets/ufo_light_damage.png"), 1);
Sprite sUFO_heavyDamage(new Surface("assets/ufo_heavy_damage.png"), 1);

// Sprites are shared across gameObjects. Might become an issue if I wanna do flashing 
unordered_map<string, Sprite*> SpriteList::sprites =
{
	{ "ball", &sBall },
	{ "tank", &sTank },
	{ "house", &sHouse },
	{ "cow", &sCow },
	{ "UFO_3hp", &sUFO_noDamage },
	{ "UFO_2hp", &sUFO_lightDamage },
	{ "UFO_1hp", &sUFO_heavyDamage },


};

