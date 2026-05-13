#include "missilePool.h"
#include "gameObject.h"


using namespace Tmpl8;
using namespace std;

void MissilePool::InstantiateToPool(GameObject* player)
{
	/*for (int i = 0; i < poolSize; i++)
	{
		auto go = missilePrefab.Load(vec2(0, 0), player);
		go->active = false;
		pool.push_back(move(go));
	}*/
}

void MissilePool::SpawnFromPool(Missile* m, vec2 pos)
{
	m->Spawn(pos);
	m->gameObject->active = true;
}

void MissilePool::ReturnToPool(Missile* m)
{




}