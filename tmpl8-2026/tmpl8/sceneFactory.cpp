#include "sceneFactory.h"

#include "scene.h"
#include "sceneData.h"
#include "mainSceneData.h"

using namespace std;


unique_ptr<MainSceneData> mainSceneData = make_unique<MainSceneData>();


unordered_map<int, SceneData*> SceneFactory::sceneList =
{

	{ 0, mainSceneData.get()},

};


unique_ptr<Scene> SceneFactory::BuildScene(int sceneID)
{

	auto data = sceneList[sceneID];

	return make_unique<Scene>(data);


};