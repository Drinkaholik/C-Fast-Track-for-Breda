#include "playerPrefab.h"

#include "surface.h"
#include "gameObject.h"
#include "spriteList.h"
#include "scene.h"

#include "playerMove.h"
#include "playerHP.h"
#include "abductor.h"

using namespace std;
using namespace Tmpl8;


GameObject* PlayerPrefab::Load(Scene* scene, vec2 pos, int maxHP, bool runStart)
{
	auto go = make_unique<GameObject>(pos);
	auto& ref = go;

	auto spr = SpriteList::sprites["ufo_3hp"];
	auto rend = &go->AddComponent<SpriteRenderer>(spr);

	auto& col = go->AddComponent<Collider>(scene, "player", spr);
	
	go->AddComponent<PlayerMove>(&col);
	go->AddComponent<PlayerHP>(scene, maxHP);
	go->AddComponent<Abductor>(scene, &col);

	scene->GetRenderSystem()->Register(4, rend);
	return scene->AddObject(ref, runStart);

}