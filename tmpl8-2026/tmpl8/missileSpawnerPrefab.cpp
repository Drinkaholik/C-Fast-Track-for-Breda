#include "missileSpawnerPrefab.h"

#include "scene.h"
#include "missileSpawner.h"
#include "gameObject.h"
#include <memory>

using namespace Tmpl8;
using namespace std;

GameObject* MissileSpawnerPrefab::Load(Scene* scene)
{
	auto go = make_unique<GameObject>(vec2(0, 0));
	auto& ref = go;

	go->AddComponent<MissileSpawner>();

	return scene->AddObject(ref);

}