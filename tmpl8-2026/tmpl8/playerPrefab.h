#pragma once

#include "prefab.h"


class PlayerPrefab : public Prefab
{
public:

	std::shared_ptr<GameObject> Load(float xPos, float yPos) override;

};

