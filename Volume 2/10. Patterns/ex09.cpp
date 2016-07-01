/*
Modify Strategy.cpp to use a Chain of Responsibility approach,
where you keep trying different ways to get someone to say their
name without admitting you’ve forgotten it.
*/
#include <iostream>
#include <vector>

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

class SaySomething : public NameStrategy {
public:
	SaySomething() {
		phrases.push_back(new SayHi());
		phrases.push_back(new Ignore());
		phrases.push_back(new Admission());
	}

	void greet() {
		for (auto p : phrases)
			p->greet();
	}

private:
	std::vector<NameStrategy*> phrases;
};

int main() {

	SaySomething s;
	s.greet();
}
