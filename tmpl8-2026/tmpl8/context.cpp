#include "context.h"

#include "state.h"

void Context::Tick()
{
	currentState->Tick();
}

void Context::Transition(State* newState)
{
	if (currentState == newState) return;





}