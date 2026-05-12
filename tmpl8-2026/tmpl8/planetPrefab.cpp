#include "planetPrefab.h"

#include "gameObject.h"
#include "gravBody.h"
#include "gravitySystem.h"
#include "baseComponents.h"


using namespace std;
using namespace Tmpl8;


// No velocity, no debug
unique_ptr<GameObject> PlanetPrefab::Load(vec2 pos, Sprite* spr, float mass)
{
    auto go = make_unique<GameObject>(pos);
    go->AddComponent<SpriteRenderer>(spr);
    auto& col = go->AddComponent<Collider>(spr);
    auto& grav = go->AddComponent<GravBody>(mass, &col);
    GravitySystem::bodies.push_back(&grav);
    return go;
    
}


// No velocity, debug
unique_ptr<GameObject> PlanetPrefab::Load(vec2 pos, Sprite* spr, float mass, bool debug)
{
    auto go = make_unique<GameObject>(pos, debug);
    go->AddComponent<SpriteRenderer>(spr);
    auto& col = go->AddComponent<Collider>(spr);
    auto& grav = go->AddComponent<GravBody>(mass, &col);
    GravitySystem::bodies.push_back(&grav);
    return go;

}

// Velocity, no debug
unique_ptr<GameObject> Load(vec2 pos, Sprite* spr, float mass, vec2 vel)
{
    auto go = make_unique<GameObject>(pos);
    go->AddComponent<SpriteRenderer>(spr);
    auto& col = go->AddComponent<Collider>(spr);
    auto& grav = go->AddComponent<GravBody>(mass, vel, &col);
    GravitySystem::bodies.push_back(&grav);
    return go;
}

// Velocity, debug
unique_ptr<GameObject> Load(vec2 pos, Sprite* spr, float mass, vec2 vel, bool debug)
{
    auto go = make_unique<GameObject>(pos, debug);
    go->AddComponent<SpriteRenderer>(spr);
    auto& col = go->AddComponent<Collider>(spr);
    auto& grav = go->AddComponent<GravBody>(mass, vel, &col);
    GravitySystem::bodies.push_back(&grav);
    return go;
}