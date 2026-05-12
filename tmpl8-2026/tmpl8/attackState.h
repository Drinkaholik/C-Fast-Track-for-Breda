#pragma once
#include "state.h"
class AttackState : public State
{


	void Tick() override;
	void TransitionLogic() override;



};

