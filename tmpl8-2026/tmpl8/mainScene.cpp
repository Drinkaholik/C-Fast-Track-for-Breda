#include "mainScene.h"
#include "template.h"
#include "surface.h"
#include "spriteList.h"
#include "gameObject.h"
#include "camera.h"

using namespace std;

void MainSceneData::LoadObjects(vector<shared_ptr<GameObject>>* vector)
{
	// Instantiate objects
	auto oCamera = cameraPrefab.Load(0, 0);
	auto oPlayer = playerPrefab.Load(0, 0);
	auto oPlanet1 = planetPrefab.Load(100, 100, SpriteList::sprites["ball"], 10);
	auto oPlanet2 = planetPrefab.Load(200, 200, SpriteList::sprites["ball"], 10);

	oCamera->GetComponent<Camera>()->SetTarget(oPlayer.get());

	// Add to vector
	vector->push_back(oPlayer);
	vector->push_back(oPlanet1);
	vector->push_back(oPlanet2);

}