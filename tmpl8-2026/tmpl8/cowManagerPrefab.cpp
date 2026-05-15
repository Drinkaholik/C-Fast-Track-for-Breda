#include "cowManagerPrefab.h"

#include "surface.h"
#include "gameObject.h"
#include "cowManager.h"
#include "spriteFactory.h"
#include "scene.h"

using namespace std;
using namespace Tmpl8;


GameObject* CowManagerPrefab::Load(Scene* scene, bool runStart)
{
	auto go = make_unique<GameObject>(vec2(0, 0));
	auto& ref = go;

	auto& cm = go->AddComponent<CowManager>(scene);
	cm.SetPlayer(scene->GetPlayer());

	return scene->AddObject(ref, runStart);

}