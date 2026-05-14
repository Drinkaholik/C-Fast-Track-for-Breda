#include "abductor.h"

#include "gameObject.h"
#include "cowManager.h"
#include "cow.h"
#include "template.h"
#include "utils.h"
#include "scene.h"

using namespace Tmpl8;


void Abductor::Start()
{
	//cowManager = scene->GetCowManager()->GetComponent<CowManager>();
	cowManager = scene->FindFirstComponent<CowManager>();

}

void Abductor::Tick()
{
	Abduct();
}


void Abductor::Abduct()
{
	vec2 myPos = gameObject->pos;

	for (auto& cow: cowManager->GetCows())
	{
		// Check against every cow in list
		if (col->CollideAt(myPos, "cow")) 
		{
			cowManager->Abduct(cow);
		}
		
	}
}