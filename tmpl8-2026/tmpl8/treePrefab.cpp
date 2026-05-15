#include "treePrefab.h"

#include "gameObject.h"
#include "surface.h"
#include "spriteFactory.h"
#include "scene.h"

using namespace Tmpl8;
using namespace std;

GameObject* TreePrefab::Load(Scene* scene, vec2 pos, bool runStart)
{
	auto go = make_unique<GameObject>(pos);
	auto& ref = go;

	auto rend = &go->AddComponent<SpriteRenderer>("tree");

	scene->GetRenderSystem()->Register(2, rend);

	return scene->AddObject(ref, runStart);
}
