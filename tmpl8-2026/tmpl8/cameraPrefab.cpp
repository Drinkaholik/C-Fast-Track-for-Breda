#include "cameraPrefab.h"

#include "gameObject.h"
#include "baseComponents.h"
#include "camera.h"

#include "surface.h"
#include "scene.h"



using namespace std;
using namespace Tmpl8;

GameObject* CameraPrefab::Load(Scene* scene, vec2 pos, bool runStart)
{
	auto go = make_unique<GameObject>(pos);
	auto& ref = go;
	auto& cam = go->AddComponent<Camera>();
	cam.SetTarget(scene->GetPlayer());

	return scene->AddObject(ref, runStart);
}
