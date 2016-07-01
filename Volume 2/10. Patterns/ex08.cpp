/*
Modify Strategy.cpp to include State behavior, so that the
Strategy can be changed during the lifetime of the Context object.
*/

#include <iostream>

class NameStrategy {
public:
	virtual void greet() = 0;
	virtual ~NameStrategy() {}
};

class SayHi : public NameStrategy {
public:
	void greet() {
		std::cout << "Hi! How's it going?" << std::endl;
	}
};

class Ignore : public NameStrategy {
public:
	void greet() {
		std::cout << "(Pretend I don't see you)" << std::endl;
	}
};

class Admission : public NameStrategy {
public:
	void greet() {
		std::cout << "I'm sorry. I forgot your name." << std::endl;
	}
};

// The "Context" controls the strategy:
class Context {
	NameStrategy* strategy;
public:
	Context(NameStrategy* strat) : strategy(strat) {}
	void set_strategy(NameStrategy* st) { strategy = st; }
	void greet() { strategy->greet(); }
};

int main() {
	SayHi sayhi;
	Ignore ignore;
	Admission admission;

	Context c(&sayhi);
	c.greet();
	c.set_strategy(&ignore);
	c.greet();
	c.set_strategy(&admission);
	c.greet();
}
