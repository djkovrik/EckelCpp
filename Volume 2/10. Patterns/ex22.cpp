/*
Add a Sunflower type to BeeAndFlowers.cpp and notice what you need to change to accommodate this new type.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "purge.h"

using namespace std;

class Gladiolus;
class Renuculus;
class Chrysanthemum;
class Sunflower; // NEW

class Visitor {
public:
	virtual void visit(Gladiolus* f) = 0;
	virtual void visit(Renuculus* f) = 0;
	virtual void visit(Chrysanthemum* f) = 0;
	virtual void visit(Sunflower* f) = 0; // NEW
	virtual ~Visitor() {}
};

class Flower {
public:
	virtual void accept(Visitor&) = 0;
	virtual ~Flower() {}
};

class Gladiolus : public Flower {
public:
	virtual void accept(Visitor& v) {
		v.visit(this);
	}
};

class Renuculus : public Flower {
public:
	virtual void accept(Visitor& v) {
		v.visit(this);
	}
};

class Chrysanthemum : public Flower {
public:
	virtual void accept(Visitor& v) {
		v.visit(this);
	}
};

// NEW: Sunflower class
class Sunflower : public Flower {
public:
	virtual void accept(Visitor& v) {
		v.visit(this);
	}
};

// Add the ability to produce a string:
class StringVal : public Visitor {
	string s;
public:
	operator const string&() { return s; }
	virtual void visit(Gladiolus*) {
		s = "Gladiolus";
	}
	virtual void visit(Renuculus*) {
		s = "Renuculus";
	}
	virtual void visit(Chrysanthemum*) {
		s = "Chrysanthemum";
	}
	//NEW
	virtual void visit(Sunflower*) {
		s = "Sunflower";
	}
};

// Add the ability to do "Bee" activities:
class Bee : public Visitor {
public:
	virtual void visit(Gladiolus*) {
		cout << "Bee and Gladiolus" << endl;
	}
	virtual void visit(Renuculus*) {
		cout << "Bee and Renuculus" << endl;
	}
	virtual void visit(Chrysanthemum*) {
		cout << "Bee and Chrysanthemum" << endl;
	}
	//NEW
	virtual void visit(Sunflower*) {
		cout << "Bee and Sunflower" << endl;
	}
};

struct FlowerGen {
	Flower* operator()() {
		switch(rand() % 4) {
			default:
			case 0: return new Gladiolus;
			case 1: return new Renuculus;
			case 2: return new Chrysanthemum;
			case 3: return new Sunflower; // NEW
		}
	}
};

int main() {
	srand(time(0));
	vector<Flower*> v(10);
	generate(v.begin(), v.end(), FlowerGen());
	vector<Flower*>::iterator it;

	StringVal sval;
	for(it = v.begin(); it != v.end(); it++) {
		(*it)->accept(sval);
		cout << string(sval) << endl;
	}
	// Perform "Bee" operation on all Flowers:
	Bee bee;
	for(it = v.begin(); it != v.end(); it++)
		(*it)->accept(bee);
	purge(v);
}
