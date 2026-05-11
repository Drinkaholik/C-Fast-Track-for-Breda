#include "mainScene.h"
#include "spriteList.h"
#include "gameObject.h"
#include "camera.h"
#include "playerPrefab.h"
#include "planetPrefab.h"
#include "cameraPrefab.h"


using namespace std;

PlayerPrefab playerPrefab;
PlanetPrefab planetPrefab;
CameraPrefab cameraPrefab;

void MainScene::LoadScene()
{
	// Instantiate objects
	auto camera = cameraPrefab.Load(0, 0);
	auto player = playerPrefab.Load(0, 0);
	auto planet1 = planetPrefab.Load(100, 100, SpriteList::sprites["ball"], 10);
	auto planet2 = planetPrefab.Load(200, 200, SpriteList::sprites["ball"], 10);

	camera->GetComponent<Camera>()->SetTarget(player.get());

	// Add to vector
	/*sceneObjects.push_back(move(camera));
	sceneObjects.push_back(move(player));
	sceneObjects.push_back(move(planet1));
	sceneObjects.push_back(move(planet2));
	
	oCamera = sceneObjects[0].get();
	oPlayer = sceneObjects[1].get();*/
	


	Scene::LoadScene(); // Run start() on all sceneObjects

}