#pragma once
#include "state.h"
class MoveState : public State
{

public:
	void Tick() override;

	MoveState(Context* context) : State(context) {};

private:
	void TransitionLogic() override;

};

