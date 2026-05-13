#pragma once

#include "context.h"
#include "SDL_scancode.h"
#include <memory>


//#include "moveState.h"
//#include "defenseState.h"

class MoveState;
class DefenseState;
class PlayerHP;

class PlayerContext : public Context
{

public:
	// Pointers to classes - owning
	std::unique_ptr<MoveState> moveState = std::make_unique<MoveState>(this);
	std::unique_ptr<DefenseState> defenseState = std::make_unique<DefenseState>(this);

	// Pointers to components - non-owning
	PlayerHP* hp = nullptr;


	SDL_Scancode key = SDL_SCANCODE_F; // Toggles between states

private:


};

