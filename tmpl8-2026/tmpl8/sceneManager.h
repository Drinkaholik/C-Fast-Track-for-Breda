#pragma once

#include "scene.h"

class SceneManager
{

public:

	void LoadScene();
	void UnloadScene();

	void ChangeScene();

	Scene* GetScene();


private:

	Scene* currentScene;




};

