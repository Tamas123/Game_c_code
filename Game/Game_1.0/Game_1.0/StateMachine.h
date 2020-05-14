#ifndef STATEMACHINE_H
#define STATEMACHINE_H


using namespace std;

#include "SFML/Graphics.hpp"

#include<memory>
#include <stack>

class State;

class StateMachine {
public:
	StateMachine();

	void run(unique_ptr<State> state);

	void nextState();
	void lastState();

	void updateEvents();
	void update();
	void render();

	bool runing();
	bool quit();

	template <typename T>
	static unique_ptr<T> buildState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);

private:
	stack<unique_ptr<State>> state;

	bool stateResult;
	bool stateRunning;



};

template<typename T>
unique_ptr<T> StateMachine::buildState(StateMachine& machine, sf::RenderWindow& window, bool replace) {
	return unique_ptr<T>(new T(machine, window, replace));
}

#endif // !STATEMACHINE_H