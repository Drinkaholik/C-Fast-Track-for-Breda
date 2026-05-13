#include "housePrefab.h"

#include "gameObject.h"
#include "surface.h"
#include "spriteList.h"
#include "scene.h"

using namespace Tmpl8;
using namespace std;

GameObject* HousePrefab::Load(Scene* scene, vec2 pos)
{
	auto go = make_unique<GameObject>(pos);
	auto& ref = go;

	auto* spr = SpriteList::sprites["house"];
	go->AddComponent<SpriteRenderer>(spr);

	auto& col = go->AddComponent<Collider>(spr);

	return scene->AddObject(ref);
}
