#pragma once
#include "scene.h"

struct PlayerPrefab;
struct PlanetPrefab;
struct CameraPrefab;

class MainScene : public Scene
{

	void LoadScene() override;
	void LoadScene(bool debug) override;

};

