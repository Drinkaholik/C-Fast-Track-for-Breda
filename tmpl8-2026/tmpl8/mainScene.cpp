#include "mainScene.h"

#include "template.h"
#include "spriteList.h"
#include "gameObject.h"
#include "camera.h"
#include "playerPrefab.h"
#include "cameraPrefab.h"
#include "housePrefab.h"
#include "missileSpawnerPrefab.h"


using namespace std;
using namespace Tmpl8;

CameraPrefab cameraPrefab;
PlayerPrefab playerPrefab;
MissileSpawnerPrefab missileSpawnerPrefab;
HousePrefab housePrefab;


void MainScene::LoadScene(bool debug)
{
	// Instantiate objects
	// Prefabs all push themselves to the sceneObjects vector
	oCamera = cameraPrefab.Load(this, vec2(0, 0));

	missileSpawnerPrefab.Load(this);
	
	housePrefab.Load(this, vec2(0, 0));
	housePrefab.Load(this, vec2(400, 400));
	housePrefab.Load(this, vec2(-400, -400));

	// Player always needs to be on top - unless I add clouds or smth
	oPlayer = playerPrefab.Load(this, vec2(0, 0));

	oCamera->GetComponent<Camera>()->SetTarget(oPlayer);

	Scene::LoadScene(debug); // Run start() on all sceneObjects

};