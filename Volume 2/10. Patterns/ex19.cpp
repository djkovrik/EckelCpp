/*
Create a business-modeling environment with three types
of Inhabitant: Dwarf (for engineers), Elf (for marketers),
and Troll (for managers). Now create a class called Project
that instantiates the different inhabitants and causes them
to interact( ) with each other using multiple dispatching.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include "purge.h"

class Dwarf;
class Elf;
class Troll;

class Inhabitant {
public:
	virtual void interact(Inhabitant* ) = 0;
	virtual void contact(Dwarf* ) = 0;
	virtual void contact(Elf* ) = 0;
	virtual void contact(Troll* ) = 0;
	virtual ~Inhabitant() {}
};

class Dwarf : public Inhabitant {
public:
	void interact(Inhabitant* other) { other->contact(this); }
	void contact(Dwarf* other) { std::cout  << "Dwarf interracts with Dwarf;\n"; }
	void contact(Elf* other) { std::cout  << "Dwarf interracts with Elf;\n"; }
	void contact(Troll* other) { std::cout  << "Dwarf interracts with Troll;\n"; }
};

class Elf : public Inhabitant {
public:
	void interact(Inhabitant* other) { other->contact(this); }
	void contact(Dwarf* other) { std::cout  << "Elf interracts with Dwarf;\n"; }
	void contact(Elf* other) { std::cout  << "Elf interracts with Elf;\n"; }
	void contact(Troll* other) { std::cout  << "Elf interracts with Troll;\n"; }
};

class Troll : public Inhabitant {
public:
	void interact(Inhabitant* other) { other->contact(this); }
	void contact(Dwarf* other) { std::cout  << "Troll interracts with Dwarf;\n"; }
	void contact(Elf* other) { std::cout  << "Troll interracts with Elf;\n"; }
	void contact(Troll* other) { std::cout  << "Troll interracts with Troll;\n"; }
};

class Project {
public:
	Project(int pairs) {

		std::generate_n(std::back_inserter(inhabitants), pairs*2,
			[]() -> Inhabitant* {
				switch(std::rand() % 3) {
					case 0: return new Dwarf; break;
					case 1: return new Elf; break;
					case 2: return new Troll; break;
				}
				return new Dwarf;
			}
		);
	}

	void run_interactions() {

		size_t pairs = inhabitants.size() / 2;
		for (size_t i = 0; i < pairs; i++)
			inhabitants.at(i)->interact( inhabitants.at(pairs + i) );
	}

	~Project() { purge(inhabitants); }
private:
	std::vector<Inhabitant*> inhabitants;
};

int main() {

	std::srand(std::time(0));

	Project p(10);
	p.run_interactions();

return 0;
}
