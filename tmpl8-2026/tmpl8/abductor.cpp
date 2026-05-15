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

	// Check against every cow in list
	if (auto cow = col->CollideWith(myPos, "cow")) 
	{
		cowManager->Abduct(cow->gameObject->GetComponent<Cow>());
	}
		
}