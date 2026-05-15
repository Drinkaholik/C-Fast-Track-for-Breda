#include "missilePrefab.h"

#include "surface.h"
#include "gameObject.h"
#include "spriteFactory.h"
#include "missile.h"
#include "scene.h"

using namespace std;
using namespace Tmpl8;


GameObject* MissilePrefab::Load(Scene* scene, ObjectPool* pool, vec2 pos, GameObject* player, bool runStart)
{
	auto go = make_unique<GameObject>(pos);
	auto& ref = go;

	auto rend = &go->AddComponent<SpriteRenderer>("missile");

	auto& col = go->AddComponent<Collider>(scene, "missile", rend->GetSprite());
	go->AddComponent<Missile>(scene, pool, player);

	scene->GetRenderSystem()->Register(3, rend);
	return scene->AddObject(ref, runStart);

}