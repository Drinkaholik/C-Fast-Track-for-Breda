#include "planetPrefab.h"

#include "gameObject.h"
#include "baseComponents.h"


using namespace std;
using namespace Tmpl8;

shared_ptr<GameObject> PlanetPrefab::Load(float xPos, float yPos, Sprite* spr, float mass)
{
    auto go = make_shared<GameObject>(xPos, yPos, true);
    go->AddComponent<SpriteRenderer>(spr);
    auto& col = go->AddComponent<Collider>(spr);
    Central::gravBodies.push_back(
        &go->AddComponent<GravBody>(mass, 0.0f, 0.0f, col)
    );
}

shared_ptr<GameObject> Load(float xPos, float yPos, Sprite* spr, float mass, float xVel, float yVel)
{
    auto go = make_shared<GameObject>(xPos, yPos, true);
    go->AddComponent<SpriteRenderer>(spr);
    auto& col = go->AddComponent<Collider>(spr);
    Central::gravBodies.push_back(
        &go->AddComponent<GravBody>(mass, xVel, yVel, col)
    );
}