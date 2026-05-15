#include "cowPrefab.h"

#include "surface.h"
#include "gameObject.h"
#include "cow.h"
#include "spriteList.h"
#include "scene.h"

using namespace std;
using namespace Tmpl8;


GameObject* CowPrefab::Load(Scene* scene, ObjectPool* pool, vec2 pos, bool runStart)
{
	// Make gameObject
	auto go = make_unique<GameObject>(pos);
	auto& ref = go;

	// Add components
	auto spr = SpriteList::sprites["cow"];
	auto rend = &go->AddComponent<SpriteRenderer>(spr);

	auto& col = go->AddComponent<Collider>(scene, "cow", spr);
	go->AddComponent<Cow>(pool);

	scene->GetRenderSystem()->Register(1, rend);
	return scene->AddObject(ref, runStart); // Add to scenObjects and return raw ptr

}