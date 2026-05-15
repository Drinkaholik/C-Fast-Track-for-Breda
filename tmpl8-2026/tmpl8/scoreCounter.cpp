#include "scoreCounter.h"

#include "central.h"
#include "scene.h"
#include "scoreSystem.h"

using namespace std;
using namespace Tmpl8;



ScoreCounter::ScoreCounter(Scene* scene)
{
    system = scene->GetScoreSystem();
}


void ScoreCounter::Tick()
{
    ShowScore();
}

void ScoreCounter::ShowScore()
{

    int score = system->GetScore();

    Central::surface->PrintScaled(
        to_string(score).c_str(), 
        (int)screenPos.x, 
        (int)screenPos.y, 
        scaleX,
        scaleY,
        colour);

}