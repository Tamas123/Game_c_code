#include "StateMachine.h"
#include "State.h"

#include <iostream>
#include <memory>

StateMachine::StateMachine()
	: stateResult{ false }
	, stateRunning{ false }

{

}

void StateMachine::run(unique_ptr<State> state)
{
}

void StateMachine::nextState()
{
}

void StateMachine::lastState()
{
}

void StateMachine::updateEvents()
{
}

void StateMachine::update()
{
}

void StateMachine::render()
{
}

bool StateMachine::runing()
{
	return false;
}

bool StateMachine::quit()
{
	return false;
}
