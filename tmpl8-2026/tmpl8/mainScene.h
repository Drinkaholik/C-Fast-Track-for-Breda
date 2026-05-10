#pragma once
#include "sceneData.h"
#include "playerPrefab.h"
#include "planetPrefab.h"
#include "cameraPrefab.h"


struct MainSceneData : public SceneData
{

	PlayerPrefab playerPrefab;
	PlanetPrefab planetPrefab;
	CameraPrefab cameraPrefab;

	void LoadObjects(std::vector<std::shared_ptr<GameObject>>* vector) override;

};

