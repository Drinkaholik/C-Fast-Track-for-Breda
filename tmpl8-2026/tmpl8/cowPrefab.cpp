#include "cowPrefab.h"


#include "surface.h"
#include "gameObject.h"
#include "cow.h"
#include "spriteList.h"
#include "scene.h"

using namespace std;
using namespace Tmpl8;


GameObject* CowPrefab::Load(Scene* scene, vec2 pos)
{
	auto go = make_unique<GameObject>(pos);
	auto& ref = go;

	auto* spr = SpriteList::sprites["tank"];
	go->AddComponent<SpriteRenderer>(spr);

	auto& col = go->AddComponent<Collider>(spr);

	go->AddComponent<Cow>();

	return scene->AddObject(ref);

}