#include "playerPrefab.h"

#include "playerMove.h"
#include "surface.h"
#include "gameObject.h"

using namespace std;

Sprite sTank(new Surface("assets/aagun.tga"), 36);

shared_ptr<GameObject> PlayerPrefab::Load(float xPos, float yPos)
{
	auto go = make_shared<GameObject>(xPos, yPos);

	go->AddComponent<SpriteRenderer>(&sTank);
	auto& col = go->AddComponent<Collider>(&sTank);
	go->AddComponent<PlayerMove>(col);

	return go;
}