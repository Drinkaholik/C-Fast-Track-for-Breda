#include "fpsCounterPrefab.h"

#include "gameObject.h"
#include "scene.h"
#include "fpsCounter.h"


using namespace std;
using namespace Tmpl8;


GameObject* FPSCounterPrefab::Load(Scene* scene)
{
	auto go = make_unique<GameObject>(vec2(0, 0));
	auto& ref = go;

	ref->AddComponent<FPSCounter>();

	return scene->AddObject(ref, true);

}