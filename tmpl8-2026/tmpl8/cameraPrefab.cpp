#include "cameraPrefab.h"

#include "gameObject.h"
#include "baseComponents.h"
#include "camera.h"
#include "surface.h"



using namespace std;
using namespace Tmpl8;

unique_ptr<GameObject> CameraPrefab::Load(vec2 pos)
{
	auto go = make_unique<GameObject>(pos);
	go->AddComponent<Camera>(nullptr);

	return go;
}
