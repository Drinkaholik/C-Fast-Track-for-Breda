#pragma once

#include "baseComponents.h"

class State;

// Abstract class

// Only the context class is a component
// States are simple classes to keep things lightweight
// Each state handles its own transition conditions, but context handles the transition itself


class Context : public Component
{
public:

private:

	State* currentState;

	void Tick() override;

	virtual void Transition(State* newState) = 0;

};




