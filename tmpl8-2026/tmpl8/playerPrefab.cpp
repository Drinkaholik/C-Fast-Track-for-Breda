#include "playerPrefab.h"

#include "playerMove.h"
#include "surface.h"
#include "gameObject.h"

using namespace std;
using namespace Tmpl8;

Sprite sTank(new Surface("assets/aagun.tga"), 36);

shared_ptr<GameObject> PlayerPrefab::Load(float xPos, float yPos)
{

	auto go = make_shared<GameObject>(xPos, yPos);

	go->AddComponent<SpriteRenderer>(&sTank);
	go->AddComponent<Collider>(&sTank);
	go->AddComponent<PlayerMove>(go->GetComponent<Collider>());

	return go;

}