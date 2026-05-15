#include "mainSceneData.h"

#include "scene.h"
#include "template.h"
#include "utils.h"

#include "playerPrefab.h"
#include "cameraPrefab.h"
#include "treePrefab.h"

#include "missileSpawnerPrefab.h"
#include "cowManagerPrefab.h"

#include "fpsCounterPrefab.h"
#include "scoreCounterPrefab.h"


using namespace Tmpl8;
using namespace std;


CameraPrefab cameraPrefab;
PlayerPrefab playerPrefab;
MissileSpawnerPrefab missileSpawnerPrefab;
TreePrefab treePrefab;
CowManagerPrefab cowManagerPrefab;
FPSCounterPrefab fpsCounterPrefab;
ScoreCounterPrefab scoreCounterPrefab;


void MainSceneData::LoadScene(Scene* scene)
{
	scene->GetSceneObjects()->reserve(2000); // bad!!!

	// Instantiate objects
	// Prefabs all push themselves to scene->sceneObjects in Load()
	fpsCounterPrefab.Load(scene);
	scoreCounterPrefab.Load(scene);


	treePrefab.Load(scene, vec2(100, 100), false);

	for (int i = 0; i < 800; i++) // Spawn trees randomly 
	{
		float x = utils::random_range(4000.0f);
		float y = utils::random_range(4000.0f);

		treePrefab.Load(scene, vec2(x, y), false);
	}

	// Player always needs to render on top - unless I add clouds or smth

	scene->SetPlayer(playerPrefab.Load(scene, vec2(0, 0), 3, false));
	scene->SetCamera(cameraPrefab.Load(scene, vec2(0, 0), false));

	cowManagerPrefab.Load(scene, false);

	missileSpawnerPrefab.Load(scene, false);
}