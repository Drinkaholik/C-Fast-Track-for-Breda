#include "cameraPrefab.h"

#include "gameObject.h"
#include "baseComponents.h"
#include "surface.h"


using namespace std;

std::shared_ptr<GameObject> CameraPrefab::Load(float xPos, float yPos)
{
	auto go = make_shared<GameObject>(xPos, yPos);
	go->AddComponent<Camera>(nullptr);

	return go;
}
