#include "UI.h"

#include "template.h"
#include "surface.h"

using namespace Tmpl8;

void UI::DrawHPBar(vec2 p1, vec2 p2, Pixel* backgroundColour, Pixel* fillColour, float ratio)
{
	// Clamp ratio
	if (ratio < 0) ratio = 0;
	if (ratio > 1) ratio = 1;




}