/*
Define some concrete mixin classes that represent superhero
capabilities (such as StopTrain, BendSteel, ClimbBuilding, etc.).
Redo exercise 4 so that your derived SuperHero classes derive from
these mixins and call their member functions.

Exercise 4:
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

class FlyAbility {
public:
	void flyOuttaThere() { std::cout << "FlyAbility::flyOuttaThere()\n"; }
};

class KillAbility {
public:
	void killThemAll() { std::cout << "KillAbility::killThemAll()\n"; }
};


class SuperlativeMan : public SuperHero, public FlyAbility {
public:
	void savePersonFromFire() { std::cout << "SuperlativeMan::savePersonFromFire()\n"; }
	void move() { std::cout << "SuperlativeMan::move()\n"; flyOuttaThere(); }
};

class Amoeba : public Animal, public SuperHero, public KillAbility {
public:
	void makeNoise() { std::cout << "Amoeba::makeNoise()\n"; }
	void savePersonFromFire() { std::cout << "Amoeba::savePersonFromFire()\n"; }
	void move() { std::cout << "Amoeba::move()\n"; killThemAll(); }
};

class TarantulaWoman : public Animal, public SuperHero, public FlyAbility {
public:
	void makeNoise() { std::cout << "TarantulaWoman::makeNoise()\n"; }
	void savePersonFromFire() { std::cout << "TarantulaWoman::savePersonFromFire()\n"; }
	void move() { std::cout << "TarantulaWoman::move()\n"; flyOuttaThere(); }
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
