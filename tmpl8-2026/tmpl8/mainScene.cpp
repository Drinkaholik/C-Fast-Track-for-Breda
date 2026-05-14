#include "mainScene.h"

#include "template.h"
#include "spriteList.h"
#include "gameObject.h"
#include "camera.h"
#include "playerPrefab.h"
#include "cameraPrefab.h"
#include "housePrefab.h"
#include "missileSpawnerPrefab.h"
#include "cowManagerPrefab.h"


using namespace std;
using namespace Tmpl8;

// Could make Load() static so I dont need to hold an object of each prefab
CameraPrefab cameraPrefab;
PlayerPrefab playerPrefab;
MissileSpawnerPrefab missileSpawnerPrefab;
HousePrefab housePrefab;
CowManagerPrefab cowManagerPrefab;

void MainScene::LoadScene()
{
	sceneObjects.reserve(600); // bad!!!

	// Instantiate objects
	// Prefabs all push themselves to scene->sceneObjects in Load()
	housePrefab.Load(this, vec2(0, 0), false);
	housePrefab.Load(this, vec2(400, 0), false);
	housePrefab.Load(this, vec2(-400, 0), false);
	housePrefab.Load(this, vec2(0, -400), false);
	housePrefab.Load(this, vec2(0, 400), false);

	// Player always needs to render on top - unless I add clouds or smth
	
	oPlayer = playerPrefab.Load(this, vec2(0, 0), 3, false);
	oCamera = cameraPrefab.Load(this, vec2(0, 0), false);

	cowManagerPrefab.Load(this, false);

	missileSpawnerPrefab.Load(this, false);
	
	Scene::LoadScene();

};