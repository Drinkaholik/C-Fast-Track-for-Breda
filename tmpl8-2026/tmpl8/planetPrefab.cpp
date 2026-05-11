#include "planetPrefab.h"

#include "gameObject.h"
#include "gravBody.h"
#include "gravitySystem.h"
#include "baseComponents.h"


using namespace std;
using namespace Tmpl8;

unique_ptr<GameObject> PlanetPrefab::Load(float xPos, float yPos, Sprite* spr, float mass)
{
    auto go = make_unique<GameObject>(xPos, yPos, true);
    go->AddComponent<SpriteRenderer>(spr);
    auto& col = go->AddComponent<Collider>(spr);
    auto& grav = go->AddComponent<GravBody>(mass, 0.0f, 0.0f, &col);
    GravitySystem::bodies.push_back(&grav);
    return go;
    
}

unique_ptr<GameObject> Load(float xPos, float yPos, Sprite* spr, float mass, float xVel, float yVel)
{
    auto go = make_unique<GameObject>(xPos, yPos, true);
    go->AddComponent<SpriteRenderer>(spr);
    auto& col = go->AddComponent<Collider>(spr);
    auto& grav = go->AddComponent<GravBody>(mass, xVel, yVel, &col);
    GravitySystem::bodies.push_back(&grav);
    return go;
}