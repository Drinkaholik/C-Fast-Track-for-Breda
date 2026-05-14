#include "objectPool.h"
#include "gameObject.h"


using namespace Tmpl8;
using namespace std;



GameObject* ObjectPool::SpawnFromPool()
{
	auto& go = pool.front();
	pool.pop();
	go->active = true;
	return go;
}

void ObjectPool::ReturnToPool(GameObject* go)
{
	pool.push(go);
	go->active = false;
}