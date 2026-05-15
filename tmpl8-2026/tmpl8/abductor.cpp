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
	if (!canAbduct) return;

	vec2 myPos = gameObject->pos;

	// Check against every cow in list
	auto cow = col->CollideWith(myPos, "cow");
	if (cow == nullptr) return;
	
	cowManager->Abduct(cow->gameObject->GetComponent<Cow>());
	
}