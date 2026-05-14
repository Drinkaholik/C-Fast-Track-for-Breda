#include "cowManager.h"

#include "utils.h"

using namespace Tmpl8;
using namespace std;



void CowManager::Start()
{
	for (SpawnGroup s : groups)
	{
		totalWeight += s.weight;
	}
}


void CowManager::Tick()
{




}




void CowManager::SetGroupSize()
{
	// Uses weighted spawn
	float rWeight = Rand(totalWeight);
	float cumWeight = 0;

	for (SpawnGroup s : groups)
	{
		cumWeight += s.weight;
		if (cumWeight >= rWeight)
		{
			currentGroup = s;
			break;
		}
	}
}

//void CowManager::Spawn(int group, int groupRange, float groupDistance, float groupDistanceRange)
//{
//
//	for (int i = 0; i < group + utils::random_range(groupRange); i++)
//	{
//
//		spawnCentre = SetSpawnCentre();
//
//	}
//
//}

//vec2 CowManager::SetSpawnCentre()
//{
//
//
//
//}
//
//vec2 CowManager::SetSpawnPos()
//{
//
//}