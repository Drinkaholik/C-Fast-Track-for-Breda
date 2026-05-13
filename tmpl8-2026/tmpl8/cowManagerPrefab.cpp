#include "cowManagerPrefab.h"

#include "surface.h"
#include "gameObject.h"
#include "cowManager.h"
#include "spriteList.h"
#include "scene.h"

using namespace std;
using namespace Tmpl8;


GameObject* CowManagerPrefab::Load(Scene* scene)
{
	auto go = make_unique<GameObject>(vec2(0, 0));
	auto& ref = go;

	go->AddComponent<CowManager>();

	return scene->AddObject(ref);

}