#include "playerPrefab.h"

#include "playerMove.h"
#include "playerHP.h"
#include "surface.h"
#include "gameObject.h"
#include "spriteList.h"
#include "scene.h"

using namespace std;
using namespace Tmpl8;


GameObject* PlayerPrefab::Load(Scene* scene, vec2 pos, int maxHP)
{
	auto go = make_unique<GameObject>(pos);
	auto& ref = go;

	auto* spr = SpriteList::sprites["UFO_3hp"];
	go->AddComponent<SpriteRenderer>(spr);

	auto& col = go->AddComponent<Collider>(spr);
	
	go->AddComponent<PlayerMove>(&col);
	go->AddComponent<PlayerHP>(maxHP);

	return scene->AddObject(ref);

}