#include "missilePrefab.h"

#include "surface.h"
#include "gameObject.h"
#include "spriteList.h"
#include "missile.h"
#include "scene.h"

using namespace std;
using namespace Tmpl8;


GameObject* MissilePrefab::Load(Scene* scene, ObjectPool* pool, vec2 pos, GameObject* player)
{
	auto go = make_unique<GameObject>(pos);
	auto& ref = go;

	auto* spr = SpriteList::sprites["tank"];
	go->AddComponent<SpriteRenderer>(spr);

	auto& col = go->AddComponent<Collider>(spr);
	go->AddComponent<Missile>(pool, player);

	return scene->AddObject(ref);

}