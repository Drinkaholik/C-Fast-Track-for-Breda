#include "cameraPrefab.h"

#include "gameObject.h"
#include "baseComponents.h"

#include "surface.h"
#include "scene.h"



using namespace std;
using namespace Tmpl8;

GameObject* CameraPrefab::Load(Scene* scene, vec2 pos)
{
	auto go = make_unique<GameObject>(pos);
	auto& ref = go;
	go->AddComponent<Camera>(nullptr);
	return scene->AddObject(ref);
}
