#include "spriteList.h"


using namespace Tmpl8;
using namespace std;

// Init sprite instances here
Sprite sBall(new Surface("assets/ball.png"), 1);
Sprite sTank(new Surface("assets/aagun.tga"), 16);


// Sprites are shared across gameObjects. Might become an issue if I wanna do flashing 
unordered_map<string, Sprite*> SpriteList::sprites =
{
	{ "ball", &sBall },
	{ "tank", &sTank }


};

