#include "central.h"

using namespace std;


Game* Central::game = nullptr;
Surface* Central::surface = nullptr;

vector<shared_ptr<GameObject>> Central::spawnedObjects;
vector<shared_ptr<GameObject>> Central::gravBodies;

float Central::deltaTime = 0;




