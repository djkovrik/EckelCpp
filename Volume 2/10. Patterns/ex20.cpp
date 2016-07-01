/*
Modify the previous exercise to make the interactions more detailed.
Each Inhabitant can randomly produce a Weapon using getWeapon( ):
a Dwarf uses Jargon or Play, an Elf uses InventFeature or SellImaginaryProduct,
and a Troll uses Edict and Schedule. You decide which weapons “win” and “lose”
in each interaction (as in PaperScissorsRock.cpp). Add a battle( ) member
function to Project that takes two Inhabitants and matches them against each
other. Now create a meeting( ) member function for Project that creates groups
of Dwarf, Elf, and Manager and battles the groups against each other until
only members of one group are left standing. These are the “winners.”

Exercise 19:
Create a business-modeling environment with three types
of Inhabitant: Dwarf (for engineers), Elf (for marketers),
and Troll (for managers). Now create a class called Project
that instantiates the different inhabitants and causes them
to interact( ) with each other using multiple dispatching.
*/

#include <iostream>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include "purge.h"

enum Outcome { WIN, LOSE, DRAW};

std::ostream& operator<<(std::ostream& os, const Outcome out) {
	switch(out) {
		default:
		case WIN: return os << "win";
		case LOSE: return os << "lose";
		case DRAW: return os << "draw";
	}
}

class Jargon; class Play;
class InventFeature; class SellImaginaryProduct;
class Edict; class Schedule;

/*
WEAPON TRAITS:
	Jargon vs Play = WIN
	Jargon vs InventFeature = LOSE
	Jargon vs SellImaginaryProduct = WIN
	Jargon vs Edict = LOSE
	Jargon vs Schedule = WIN
	Play vs InventFeature = LOSE
	Play vs SellImaginaryProduct = WIN
	Play vs Edict = LOSE
	Play vs Schedule = WIN
	InventFeature vs SellImaginaryProduct = LOSE
	InventFeature vs Edict = WIN
	InventFeature vs Schedule = LOSE
	SellImaginaryProduct vs Edict = WIN
	SellImaginaryProduct vs Schedule = LOSE
	Edict vs Schedule = WIN
*/

// Weapons
class Weapon {
public:
	virtual Outcome compare(const Weapon* )  = 0;
	virtual Outcome clash(const Jargon* ) const = 0;
	virtual Outcome clash(const Play* ) const = 0;
	virtual Outcome clash(const InventFeature* ) const = 0;
	virtual Outcome clash(const SellImaginaryProduct* ) const = 0;
	virtual Outcome clash(const Edict* ) const = 0;
	virtual Outcome clash(const Schedule* ) const = 0;
	virtual ~Weapon() = default;
};
// Dwarven
class Jargon : public Weapon {
public:
	Outcome compare(const Weapon* w) { return w->clash(this); }
	Outcome clash(const Jargon* j) const { return DRAW; }
	Outcome clash(const Play* p) const { return WIN; }
	Outcome clash(const InventFeature* i) const { return LOSE; }
	Outcome clash(const SellImaginaryProduct* s) const { return WIN; }
	Outcome clash(const Edict* e) const { return LOSE; }
	Outcome clash(const Schedule* s) const { return WIN; }
};

class Play : public Weapon {
public:
	Outcome compare(const Weapon* w) { return w->clash(this); }
	Outcome clash(const Jargon* j) const { return LOSE; }
	Outcome clash(const Play* p) const { return DRAW; }
	Outcome clash(const InventFeature* i) const { return LOSE; }
	Outcome clash(const SellImaginaryProduct* s) const { return WIN; }
	Outcome clash(const Edict* e) const { return LOSE; }
	Outcome clash(const Schedule* s) const { return WIN; }
};
// Elven
class InventFeature : public Weapon {
public:
	Outcome compare(const Weapon* w) { return w->clash(this); }
	Outcome clash(const Jargon* j) const { return WIN; }
	Outcome clash(const Play* p) const { return WIN; }
	Outcome clash(const InventFeature* i) const { return DRAW; }
	Outcome clash(const SellImaginaryProduct* s) const { return LOSE; }
	Outcome clash(const Edict* e) const { return WIN; }
	Outcome clash(const Schedule* s) const { return LOSE; }
};

class SellImaginaryProduct : public Weapon {
public:
	Outcome compare(const Weapon* w) { return w->clash(this); }
	Outcome clash(const Jargon* j) const { return LOSE; }
	Outcome clash(const Play* p) const { return LOSE; }
	Outcome clash(const InventFeature* i) const { return WIN; }
	Outcome clash(const SellImaginaryProduct* s) const { return DRAW; }
	Outcome clash(const Edict* e) const { return WIN; }
	Outcome clash(const Schedule* s) const { return LOSE; }
};
// Trollish
class Edict : public Weapon {
public:
	Outcome compare(const Weapon* w) { return w->clash(this); }
	Outcome clash(const Jargon* j) const { return WIN; }
	Outcome clash(const Play* p) const { return WIN; }
	Outcome clash(const InventFeature* i) const { return LOSE; }
	Outcome clash(const SellImaginaryProduct* s) const { return LOSE; }
	Outcome clash(const Edict* e) const { return DRAW; }
	Outcome clash(const Schedule* s) const { return WIN; }
};

class Schedule : public Weapon {
public:
	Outcome compare(const Weapon* w) { return w->clash(this); }
	Outcome clash(const Jargon* j) const { return LOSE; }
	Outcome clash(const Play* p) const { return LOSE; }
	Outcome clash(const InventFeature* i) const { return WIN; }
	Outcome clash(const SellImaginaryProduct* s) const { return WIN; }
	Outcome clash(const Edict* e) const { return LOSE; }
	Outcome clash(const Schedule* s) const { return DRAW; }
};

// Inhabitants
class Dwarf; class Elf; class Troll;

class Inhabitant {
public:
	virtual Weapon* get_weapon() const = 0;
	virtual ~Inhabitant() = default;

	virtual Outcome fight(Inhabitant* other) {

		Weapon* a = get_weapon();
		Weapon* b = other->get_weapon();

		std::cout << typeid(*this).name() << " with " << typeid(*a).name()
				  << " vs. " << typeid(*other).name() << " with " << typeid(*b).name() << '\n';

		Outcome result = b->compare(a);
		delete a; delete b;
		return result;
	}
};

class Dwarf : public Inhabitant {
public:
	Weapon* get_weapon() const {
		if ( std::rand() % 2 )
			return new Jargon;

		return new Play;
	}
};

class Elf : public Inhabitant {
public:

	Weapon* get_weapon() const {
		if ( std::rand() % 2 )
			return new InventFeature;

		return new SellImaginaryProduct;
	}
};

class Troll : public Inhabitant {
public:

	Weapon* get_weapon() const {
		if ( std::rand() % 2 )
			return new Edict;

		return new Schedule;
	}
};

class Project {
public:
	Project(int c) : count(c) {}

	void set_count(int c) { count = c; }

	void populate_for_battle() {

		std::generate_n(std::back_inserter(inhabitants), count*2,
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

	Outcome battle(Inhabitant* a, Inhabitant* b) {

		Outcome result = b->fight(a);

		switch (result) {
			case WIN: std::cout << typeid(*b).name() << " wins!\n"; break;
			case LOSE: std::cout << typeid(*b).name() << " loses!\n"; break;
			default: std::cout << "It's a draw!\n"; break;
		}

		return result;
	}

	void run_battles() {

		populate_for_battle();

		size_t pairs = inhabitants.size() / 2;
		for (size_t i = 0; i < pairs; i++)
			battle(inhabitants.at(i), inhabitants.at(pairs + i) );

	}

	void populate_for_meeting() {

		for (size_t i = 0; i < count; ++i) {
			dwarwes.push_back( new Dwarf );
			elves.push_back( new Elf );
			trolls.push_back( new Troll );
		}
	}

	void meeting() {

		populate_for_meeting();

		bool dwarwes_available = true;
		bool elves_available = true;
		bool trolls_available = true;

		while (true) {

			int empty_containers = 0;

			if ( !dwarwes_available ) { ++empty_containers; }
			if ( !elves_available ) { ++empty_containers; }
			if ( !trolls_available ) { ++empty_containers; }

			std::cout << "\nITERATION:"
				      << "\nempty_containers = " << empty_containers
					  << "\ndwarwes_available = " << dwarwes_available
					  << "\nelves_available = " << elves_available
					  << "\ntrolls_available = " << trolls_available
					  << "\ndwarwes.size() = " << dwarwes.size()
					  << "\nelves.size() = " << elves.size()
					  << "\ntrolls.size() = " << trolls.size() << '\n';

			if (empty_containers >= 2) {
				std::cout << "empty_containers >= 2 detected! BREAK!\n";
				break;
			}

			// Dwarf vs. Elf
			if (dwarwes_available && elves_available) {
				auto combatant1 = dwarwes.back();
				auto combatant2 = elves.back();
				auto result = battle(combatant2, combatant1);

				switch(result) {
					case WIN: elves.pop_back(); break;
					case LOSE: dwarwes.pop_back(); break;
				}
			}

			if ( dwarwes.empty() ) { dwarwes_available = false; }
			if ( elves.empty() ) { elves_available = false; }

			std::cout << "\ndwarwes_available = " << dwarwes_available
					  << "\nelves_available = " << elves_available
					  << "\ndwarwes.size() = " << dwarwes.size()
					  << "\nelves.size() = " << elves.size() << '\n';

			//Elf vs. Troll
			if (elves_available && trolls_available) {
				auto combatant1 = elves.back();
				auto combatant2 = trolls.back();
				auto result = battle(combatant2, combatant1);

				switch(result) {
					case WIN: trolls.pop_back(); break;
					case LOSE: elves.pop_back(); break;
				}
			}

			if ( elves.empty() ) { elves_available = false; }
			if ( trolls.empty() ) { trolls_available = false; }

			std::cout << "\nelves_available = " << elves_available
					  << "\ntrolls_available = " << trolls_available
					  << "\nelves.size() = " << elves.size()
					  << "\ntrolls.size() = " << trolls.size() << '\n';

			//Dwarf vs. Troll
			if (dwarwes_available && trolls_available) {
				auto combatant1 = dwarwes.back();
				auto combatant2 = trolls.back();
				auto result = battle(combatant2, combatant1);

				switch(result) {
					case WIN: trolls.pop_back(); break;
					case LOSE: dwarwes.pop_back(); break;
				}
			}

			if ( dwarwes.empty() ) { dwarwes_available = false; }
			if ( trolls.empty() ) { trolls_available = false; }

			std::cout << "\ndwarwes_available = " << dwarwes_available
					  << "\ntrolls_available = " << trolls_available
					  << "\ndwarwes.size() = " << dwarwes.size()
					  << "\ntrolls.size() = " << trolls.size() << '\n';

		}

		if ( dwarwes_available ) std::cout << "\nDWARWES WON!\n";
		else if ( elves_available ) std::cout << "\nELWES WON!\n";
		else if ( trolls_available ) std::cout << "\nTROLLS WON!\n";
		else std::cout << "SOMETHING WRONG HERE!\n";
	}

	~Project() {
		purge(inhabitants);
		purge(dwarwes);
		purge(elves);
		purge(trolls);
	}

private:
	size_t count;

	std::vector<Inhabitant*> inhabitants;
	std::vector<Dwarf*> dwarwes;
	std::vector<Elf*> elves;
	std::vector<Troll*> trolls;
};

int main() {

	std::srand(std::time(0));
	std::cout.setf(std::ios::unitbuf);

	Project p(3);
	//p.run_battles();
	p.meeting();

return 0;
}
