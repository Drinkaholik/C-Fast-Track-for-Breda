#include "scoreCounterPrefab.h"

#include "gameObject.h"
#include "scene.h"
#include "scoreCounter.h"


using namespace std;
using namespace Tmpl8;


GameObject* ScoreCounterPrefab::Load(Scene* scene)
{
	auto go = make_unique<GameObject>(vec2(0, 0));
	auto& ref = go;

	ref->AddComponent<ScoreCounter>(scene);

	return scene->AddObject(ref, true);

}