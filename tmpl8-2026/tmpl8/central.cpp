#include "central.h"

using namespace std;


Game* Central::game = nullptr;
Surface* Central::surface = nullptr;
GameObject* Central::camera = nullptr;

vector<shared_ptr<GameObject>> Central::spawnedObjects;
vector<GravBody*> Central::gravBodies;

float Central::deltaTime = 0;



