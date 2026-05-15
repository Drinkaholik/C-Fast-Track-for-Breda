#include "fpsCounter.h"

#include "gameObject.h"
#include <cmath>

#include "central.h"

using namespace std;
using namespace Tmpl8;



void FPSCounter::Tick()
{
    ShowFPS();
}



void FPSCounter::ShowFPS()
{
    // Why mult by 1000 specifically? Measured in milliseconds?
        // Idk but it matches what i can see with sprite movement
    float realFPS = (1 / Central::dts);

    // Higher value as the gap between realFPS and smoothedFPS increases,
    // stops it from taking ages to catch up
    float dynamicSmoothing = (abs(1 - realFPS / smoothedFPS)) / smoothing;

    smoothedFPS = (int)lerp(smoothedFPS, realFPS, dynamicSmoothing);

    Central::surface->PrintScaled(
        to_string(smoothedFPS).c_str(),
        (int)screenPos.x,
        (int)screenPos.y,
        scaleX,
        scaleY,
        colour);

}