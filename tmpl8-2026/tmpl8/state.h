#pragma once


class Context;

// Abstract class

// States aren't components so I don't have to call AddComponent or RemoveComponent on transition
// Each state handles its own transition conditions, but calls context->Transition() to perform the transition itself

class State
{
public:

	State(Context* context) : context(context) {};

	virtual void Tick() = 0;

private:

	Context* context;

	virtual void TransitionLogic() = 0; // Calls context->Transition based on certain conditions


	
};

