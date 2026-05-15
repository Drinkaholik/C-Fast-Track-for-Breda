#pragma once

#include <memory>
#include <unordered_map>

class Scene;
class SceneData;


class SceneFactory
{


public:

	static std::unique_ptr<Scene> BuildScene(int sceneID);


private:



	static std::unordered_map<int, SceneData*> sceneList;

	

};

