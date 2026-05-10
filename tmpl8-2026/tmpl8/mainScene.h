#pragma once
#include "scene.h"
#include "planetPrefab.h"


class MainScene : public Scene
{

	PlayerPrefab playerPrefab;
	PlanetPrefab planetPrefab;

	void LoadScene() override;


};

