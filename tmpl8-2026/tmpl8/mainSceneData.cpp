#include "mainSceneData.h"

#include "scene.h"
#include "template.h"

#include "playerPrefab.h"
#include "cameraPrefab.h"
#include "housePrefab.h"
#include "missileSpawnerPrefab.h"
#include "cowManagerPrefab.h"


using namespace Tmpl8;
using namespace std;


CameraPrefab cameraPrefab;
PlayerPrefab playerPrefab;
MissileSpawnerPrefab missileSpawnerPrefab;
HousePrefab housePrefab;
CowManagerPrefab cowManagerPrefab;


void MainSceneData::LoadScene(Scene* scene)
{
	scene->GetSceneObjects()->reserve(600); // bad!!!

	// Instantiate objects
	// Prefabs all push themselves to scene->sceneObjects in Load()
	housePrefab.Load(scene, vec2(0, 0), false);
	housePrefab.Load(scene, vec2(400, 0), false);
	housePrefab.Load(scene, vec2(-400, 0), false);
	housePrefab.Load(scene, vec2(0, -400), false);
	housePrefab.Load(scene, vec2(0, 400), false);

	// Player always needs to render on top - unless I add clouds or smth

	scene->SetPlayer(playerPrefab.Load(scene, vec2(0, 0), 3, false));
	scene->SetCamera(cameraPrefab.Load(scene, vec2(0, 0), false));

	cowManagerPrefab.Load(scene, false);

	missileSpawnerPrefab.Load(scene, false);
}