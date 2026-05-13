#pragma once

#include "context.h"
#include "SDL_scancode.h"
#include <memory>


//#include "moveState.h"
//#include "defenseState.h"
//#include "attackState.h"

class MoveState;
class DefenseState;
class AttackState;

class PlayerContext : public Context
{

public:
	// Pointers to all classes
	std::unique_ptr<MoveState> moveState = std::make_unique<MoveState>(this);
	std::unique_ptr<DefenseState> defenseState = std::make_unique<DefenseState>(this);
	std::unique_ptr<AttackState> attackState = std::make_unique<AttackState>(this);


	SDL_Scancode key1 = SDL_SCANCODE_1; // Transition to state 1
	SDL_Scancode key2 = SDL_SCANCODE_2; // Transition to state 2
	SDL_Scancode key3 = SDL_SCANCODE_3; // Transition to state 3

private:


};

