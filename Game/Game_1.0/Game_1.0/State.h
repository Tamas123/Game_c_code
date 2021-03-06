#ifndef STATE_H
#define STATE_H

#include "SFML/Graphics.hpp"
#include <memory>
using namespace std;

class StateMachine;

class State

{
private:

	State(StateMachine& machine, sf::RenderWindow& window, bool replace = true);
	virtual ~State() = default;

	State(const State&) = delete;
	State& operator = (const State&) = delete;

	virtual void updateEvents() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	unique_ptr<State> nextState();

	bool isReplacing();

protected:
	StateMachine& machine;
	sf::RenderWindow& window;

	bool replacing;

	unique_ptr<State> next;


};

#endif // !STATE_H