#include "cameraPrefab.h"

#include "gameObject.h"
#include "baseComponents.h"
#include "camera.h"
#include "surface.h"


using namespace std;

unique_ptr<GameObject> CameraPrefab::Load(float xPos, float yPos)
{
	auto go = make_unique<GameObject>(xPos, yPos);
	go->AddComponent<Camera>(nullptr);

	return go;
}
