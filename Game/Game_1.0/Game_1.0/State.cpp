#include "State.h"

State::State(StateMachine& machine, sf::RenderWindow& window, bool replace)
	: machine{machine}
	, window{window}
	, replacing{replace}

{
}

unique_ptr<State> State::nextState()
{
	return move(next);
}

bool State::isReplacing()
{
	return replacing;
}
