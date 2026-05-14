//#include "missilePool.h"
//#include "gameObject.h"
//#include "missilePrefab.h"
//#include "missile.h"
//
//
//using namespace Tmpl8;
//using namespace std;
//
//MissilePrefab missilePrefab;
//
////void MissilePool::InstantiateToPool(Scene* scene, GameObject* player)
////{
////	for (int i = 0; i < poolSize; i++)
////	{
////		auto go = missilePrefab.Load(scene, this, vec2(0, 0), player);
////		go->active = false;
////		pool.push(go->GetComponent<Missile>());
////	}
////}
//
//Missile* MissilePool::SpawnFromPool()
//{
//	auto& m = pool.front();
//	pool.pop();
//	m->gameObject->active = true;
//	return m;
//}
//
//void MissilePool::ReturnToPool(Missile* m)
//{
//	pool.push(m);
//	m->gameObject->active = false;
//}