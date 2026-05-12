#include "playerPrefab.h"

#include "playerMove.h"
#include "surface.h"
#include "gameObject.h"
#include "spriteList.h"
#include "gravBody.h"

using namespace std;
using namespace Tmpl8;


unique_ptr<GameObject> PlayerPrefab::Load(vec2 pos)
{
	auto go = make_unique<GameObject>(pos);

	auto spr = SpriteList::sprites["tank"];

	go->AddComponent<SpriteRenderer>(spr);
	auto& col = go->AddComponent<Collider>(spr);
	go->AddComponent<GravBody>(20, &col);
	go->AddComponent<PlayerMove>(&col);

	return go;
}