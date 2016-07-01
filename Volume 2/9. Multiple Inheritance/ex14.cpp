/*
Suppose you are given a pre-compiled Person class
(you only have the header and compiled object file).
Suppose also that Person has a non-virtual work( )
function. Have SuperHero be able to act as a mild-mannered
ordinary Person by deriving from Person and using the
implementation of Person::work( ), but make
SuperHero::work( ) virtual.
*/

#include <iostream>

class Person {
public:
	void work();
};

/* Somewhere in outer files */
void Person::work() { std::cout << "Person::work()\n"; }

class Animal {
public:
	virtual void makeNoise() = 0;
	virtual void move() = 0;
	virtual ~Animal() {}
};

class SuperHero : public Person {
public:
	virtual void savePersonFromFire() = 0;
	virtual void move() = 0;
	virtual ~SuperHero() {}
	virtual void work() { Person::work(); }
};

class SuperlativeMan : public SuperHero {
public:
	void savePersonFromFire() { std::cout << "SuperlativeMan::savePersonFromFire()\n"; }
	void move() { std::cout << "SuperlativeMan::move()\n"; }
};

class Amoeba : public Animal, public SuperHero {
public:
	void makeNoise() { std::cout << "Amoeba::makeNoise()\n"; }
	void savePersonFromFire() { std::cout << "Amoeba::savePersonFromFire()\n"; }
	void move() { std::cout << "Amoeba::move()\n"; }
};

class TarantulaWoman : public Animal, public SuperHero {
public:
	void makeNoise() { std::cout << "TarantulaWoman::makeNoise()\n"; }
	void savePersonFromFire() { std::cout << "TarantulaWoman::savePersonFromFire()\n"; }
	void move() { std::cout << "TarantulaWoman::move()\n"; }
};

void saveFromFire(SuperHero* s) {
	s->savePersonFromFire();
	s->move();
	s->work();
}


int main() {

	Amoeba am;
	TarantulaWoman tw;
	SuperlativeMan sm;

	saveFromFire(&am);
	saveFromFire(&tw);
	saveFromFire(&sm);

return 0;
}
