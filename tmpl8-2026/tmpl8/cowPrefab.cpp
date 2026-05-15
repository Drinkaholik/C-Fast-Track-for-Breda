#include "cowPrefab.h"

#include "surface.h"
#include "gameObject.h"
#include "cow.h"
#include "spriteFactory.h"
#include "scene.h"

using namespace std;
using namespace Tmpl8;


GameObject* CowPrefab::Load(Scene* scene, ObjectPool* pool, vec2 pos, bool runStart)
{
	// Make gameObject
	auto go = make_unique<GameObject>(pos);
	auto& ref = go;

	// Add components
	auto rend = &go->AddComponent<SpriteRenderer>("cow");

	auto& col = go->AddComponent<Collider>(scene, "cow", rend->GetSprite());
	go->AddComponent<Cow>(pool);

	scene->GetRenderSystem()->Register(1, rend);
	return scene->AddObject(ref, runStart); // Add to scenObjects and return raw ptr

}