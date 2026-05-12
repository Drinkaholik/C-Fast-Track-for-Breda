#include "playerPrefab.h"

#include "playerMove.h"
#include "surface.h"
#include "gameObject.h"
#include "spriteList.h"

using namespace std;


unique_ptr<GameObject> PlayerPrefab::Load(float xPos, float yPos)
{
	auto go = make_unique<GameObject>(xPos, yPos);

	auto spr = SpriteList::sprites["tank"];

	go->AddComponent<SpriteRenderer>(spr);
	auto& col = go->AddComponent<Collider>(spr);
	go->AddComponent<PlayerMove>(&col);

	return go;
}

unique_ptr<GameObject> PlayerPrefab::Load(float xPos, float yPos, bool debug)
{
	auto go = make_unique<GameObject>(xPos, yPos, debug);

	auto spr = SpriteList::sprites["tank"];

	go->AddComponent<SpriteRenderer>(spr);
	auto& col = go->AddComponent<Collider>(spr);
	go->AddComponent<PlayerMove>(&col);

	return go;
}