/*
Modify KissingPrincess2.cpp by adding another state to
the system, so that each kiss cycles the creature to the
next state.
*/
#include <iostream>
#include <string>

using namespace std;

class Creature {
	class State {
	public:
		virtual string response() = 0;
		virtual ~State() {}
	};
	class Monster : public State {
	public:
		string response() { return "Ugly!"; }
	};
	class Frog : public State {
	public:
		string response() { return "Ribbet!"; }
	};
	class Prince : public State {
	public:
		string response() { return "Darling!"; }
	};
	State* state;
public:
	Creature() : state(new Frog()) {}
	void greet() {
		cout << state->response() << endl;
	}

	void kiss() {

		Monster* ms = dynamic_cast<Monster*>(state);
		Frog* fs = dynamic_cast<Frog*>(state);
		Prince* ps = dynamic_cast<Prince*>(state);

		delete state;

		if (ms) {
			//std::cout << "Current state is Monster, next state is Frog\n";
			state = new Frog();
		} else if (fs) {
			//std::cout << "Current state is Frog, next state is Prince\n";
			state = new Prince();
		} else if (ps) {
			//std::cout << "Current state is Prince, next state is Monster\n";
			state = new Monster();
		}
	}
};

int main() {
	Creature creature;
	creature.greet();
	creature.kiss();
	creature.greet();
	creature.kiss();
	creature.greet();
	creature.kiss();
	creature.greet();
	creature.kiss();
	creature.greet();
	creature.kiss();
	creature.greet();
	creature.kiss();
	creature.greet();
}
