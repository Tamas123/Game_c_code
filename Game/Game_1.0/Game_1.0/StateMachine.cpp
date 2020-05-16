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
	stateRunning = true;
	states.push(move(state));
}

void StateMachine::nextState()
{
	if(stateRunning){
		if (!states.empty()) {
			states.pop();
		}

		stateResult = false;
	}

	if (!states.empty()) {
		unique_ptr<State> temp = states.top()->nextState();

		if (temp != nullptr) {
			if (temp->isReplacing()) {

				states.pop();

			}
		}
	}
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
