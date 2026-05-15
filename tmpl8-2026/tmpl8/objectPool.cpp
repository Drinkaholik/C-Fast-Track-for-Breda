#include "objectPool.h"
#include "gameObject.h"


using namespace Tmpl8;
using namespace std;



GameObject* ObjectPool::SpawnFromPool()
{
	if (pool.empty()) return nullptr;
	auto go = pool.front();
	pool.pop();
	go->SetActive(true); // Very rarely I get an access violation error here...
	return go;
}

void ObjectPool::ReturnToPool(GameObject* go)
{
	pool.push(go);
	go->SetActive(false);
}