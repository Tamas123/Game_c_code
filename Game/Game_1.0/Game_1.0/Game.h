#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "StateMachine.h"
#include "MainMenuState.h"


class Game
{
public:
	Game() = default;
	void run();

private:
};

#endif // !GAME_H