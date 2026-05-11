#include "playerPrefab.h"

#include "playerMove.h"
#include "surface.h"
#include "gameObject.h"
#include "spriteList.h"

using namespace std;


unique_ptr<GameObject> PlayerPrefab::Load(float xPos, float yPos)
{
	auto go = make_unique<GameObject>(xPos, yPos);

	go->AddComponent<SpriteRenderer>(SpriteList::sprites["ball"]);
	auto& col = go->AddComponent<Collider>(SpriteList::sprites["ball"]);
	go->AddComponent<PlayerMove>(&col);

	return go;
}