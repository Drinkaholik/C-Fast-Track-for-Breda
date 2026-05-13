#include "mainScene.h"

#include "template.h"
#include "spriteList.h"
#include "gameObject.h"
#include "camera.h"
#include "playerPrefab.h"
#include "cameraPrefab.h"


using namespace std;
using namespace Tmpl8;

PlayerPrefab playerPrefab;
CameraPrefab cameraPrefab;


void MainScene::LoadScene(bool debug)
{
	// Instantiate objects
	auto camera = cameraPrefab.Load(vec2(0, 0));
	auto player = playerPrefab.Load(vec2(0, 0));

	camera->GetComponent<Camera>()->SetTarget(player.get());

	auto star = make_unique<GameObject>(vec2(0, 0));
	star->AddComponent<SpriteRenderer>(SpriteList::sprites["star"]);

	// Add to vector
	sceneObjects.push_back(move(star));
	sceneObjects.push_back(move(camera));
	sceneObjects.push_back(move(player));

	oCamera = sceneObjects[0].get();
	oPlayer = sceneObjects[1].get();



	Scene::LoadScene(debug); // Run start() on all sceneObjects

}