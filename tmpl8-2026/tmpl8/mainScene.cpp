#include "mainScene.h"
#include "template.h"
#include "surface.h"

using namespace std;


Sprite sBall(new Surface("assets/ball.png"), 1);

void MainScene::LoadScene()
{
	auto oPlayer = playerPrefab.Load(0, 0);
	auto oPlanet1 = planetPrefab.Load(100, 100, &sBall, 10);
	auto oPlanet2 = planetPrefab.Load(200, 200, &sBall, 10);

	sceneObjects.push_back(oPlayer);
	sceneObjects.push_back(oPlanet1);
	sceneObjects.push_back(oPlanet2);

	for (auto& obj : sceneObjects)
	{
		obj->Start();
	}

}