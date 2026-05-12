#include "mainScene.h"

#include "template.h"
#include "spriteList.h"
#include "gameObject.h"
#include "camera.h"
#include "playerPrefab.h"
#include "planetPrefab.h"
#include "cameraPrefab.h"


using namespace std;
using namespace Tmpl8;

PlayerPrefab playerPrefab;
PlanetPrefab planetPrefab;
CameraPrefab cameraPrefab;

void MainScene::LoadScene()
{
	// Instantiate objects
	auto camera = cameraPrefab.Load(vec2(0, 0));
	auto player = playerPrefab.Load(vec2(0, 0));
	auto planet1 = planetPrefab.Load(vec2(100, 100), SpriteList::sprites["ball"], 10);
	auto planet2 = planetPrefab.Load(vec2(200, 200), SpriteList::sprites["ball"], 10);

	camera->GetComponent<Camera>()->SetTarget(player.get());

	// Add to vector
	sceneObjects.push_back(move(camera));
	sceneObjects.push_back(move(player));
	sceneObjects.push_back(move(planet1));
	sceneObjects.push_back(move(planet2));
	
	oCamera = sceneObjects[0].get();
	oPlayer = sceneObjects[1].get();
	


	Scene::LoadScene(); // Run start() on all sceneObjects

}

void MainScene::LoadScene(bool debug)
{
	// Instantiate objects
	auto camera = cameraPrefab.Load(vec2(0, 0));
	auto player = playerPrefab.Load(vec2(0, 0), debug);
	auto planet1 = planetPrefab.Load(vec2(100, 100), SpriteList::sprites["ball"], 10, debug);
	auto planet2 = planetPrefab.Load(vec2(200,200), SpriteList::sprites["ball"], 10, debug);

	camera->GetComponent<Camera>()->SetTarget(player.get());

	auto star = make_unique<GameObject>(vec2(0, 0));
	star->AddComponent<SpriteRenderer>(SpriteList::sprites["star"]);

	// Add to vector
	sceneObjects.push_back(move(star));
	sceneObjects.push_back(move(camera));
	sceneObjects.push_back(move(player));
	sceneObjects.push_back(move(planet1));
	sceneObjects.push_back(move(planet2));

	oCamera = sceneObjects[0].get();
	oPlayer = sceneObjects[1].get();



	Scene::LoadScene(); // Run start() on all sceneObjects

}