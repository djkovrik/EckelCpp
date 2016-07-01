/*
Make an Animal interface class with a makeNoise( )
function declaration. Make a SuperHero interface class
with a savePersonFromFire( ) function declaration.
Place a move( ) function declaration in both interface
classes. (Remember to make your interface methods pure virtual.)
Now define three separate classes: SuperlativeMan,
Amoeba (a superhero of uncertain gender), and TarantulaWoman;
SuperlativeMan implements the SuperHero interface while
Amoeba and TarantulaWoman implement both Animal and SuperHero.
Define two global functions animalSound(Animal*) and
saveFromFire(SuperHero*). Invoke all the methods that are callable
from each interface in both of these functions.
*/

#include <iostream>

class Animal {
public:
	virtual void makeNoise() = 0;
	virtual void move() = 0;
	virtual ~Animal() {}
};

class SuperHero {
public:
	virtual void savePersonFromFire() = 0;
	virtual void move() = 0;
	virtual ~SuperHero() {}
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

void animalSound(Animal* a) {
	a->makeNoise();
	a->move();
}

void saveFromFire(SuperHero* s) {
	s->savePersonFromFire();
	s->move();
}


int main() {

	Amoeba am;
	TarantulaWoman tw;
	SuperlativeMan sm;

	animalSound(&am);
	animalSound(&tw);

	saveFromFire(&am);
	saveFromFire(&tw);
	saveFromFire(&sm);


return 0;
}
