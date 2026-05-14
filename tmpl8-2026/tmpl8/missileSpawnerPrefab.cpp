#include "missileSpawnerPrefab.h"

#include "scene.h"
#include "missileSpawner.h"
#include "gameObject.h"
#include <memory>

using namespace Tmpl8;
using namespace std;

GameObject* MissileSpawnerPrefab::Load(Scene* scene, bool runStart)
{
	auto go = make_unique<GameObject>(vec2(0, 0));
	auto& ref = go;

	auto& ms = go->AddComponent<MissileSpawner>(scene);
	ms.SetPlayer(scene->GetPlayer());

	return scene->AddObject(ref, runStart);

}