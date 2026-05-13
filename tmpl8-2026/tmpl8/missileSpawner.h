#pragma once
#include "baseComponents.h"
#include "missilePool.h"
#include "missile.h"
#include <memory>



class MissileSpawner : public Component
{
	std::unique_ptr<MissilePool> pool = std::make_unique<MissilePool>();
};

