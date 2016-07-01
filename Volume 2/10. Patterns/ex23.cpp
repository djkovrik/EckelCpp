/*
Modify BeeAndFlowers.cpp so that it does not use Visitor,
but “reverts” to a regular class hierarchy instead. Turn Bee
into a collecting parameter.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "purge.h"

using namespace std;

class Flower {
public:
	virtual string name() const { return "Flower"; }
	virtual ~Flower() {}
};

class Gladiolus : public Flower {
public:
	string name() const { return "Gladiolus"; }
};

class Renuculus : public Flower {
public:
	 string name() const { return "Renuculus"; }
};

class Chrysanthemum : public Flower {
public:
	string name() const { return "Chrysanthemum"; }
};

class Bee {
public:
	void accept(Flower* f) {
		cout << "Bee and " << f->name() << endl;
	}
};

struct FlowerGen {
	Flower* operator()() {
		switch(rand() % 3) {
			default:
			case 0: return new Gladiolus;
			case 1: return new Renuculus;
			case 2: return new Chrysanthemum;
		}
	}
};

int main() {
	srand(time(0));
	vector<Flower*> v(10);
	generate(v.begin(), v.end(), FlowerGen());

	for (auto flower : v)
		std::cout << flower->name() << endl;

	Bee bee;
	for (auto flower : v)
		bee.accept(flower);

	purge(v);
}
