#pragma once
#include "state.h"
class DefenseState : public State
{


	void Tick() override;
	void TransitionLogic() override;



};

