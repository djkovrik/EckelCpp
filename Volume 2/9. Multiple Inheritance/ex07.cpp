/*
Repeat the previous exercise using templates by making your
superhero powers mixin template parameters. Use these powers
to do some good in the community.

Exercise 6:
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

class FlyAbility {
public:
	void flyOuttaThere() { std::cout << "FlyAbility::flyOuttaThere()\n"; }
};

class KillAbility {
public:
	void killThemAll() { std::cout << "KillAbility::killThemAll()\n"; }
};


class SuperlativeMan {
public:
	void savePersonFromFire() { std::cout << "SuperlativeMan::savePersonFromFire()\n"; }
	void move() { std::cout << "SuperlativeMan::move()\n"; }
};

class Amoeba {
public:
	void makeNoise() { std::cout << "Amoeba::makeNoise()\n"; }
	void savePersonFromFire() { std::cout << "Amoeba::savePersonFromFire()\n"; }
	void move() { std::cout << "Amoeba::move()\n"; }
};

class TarantulaWoman {
public:
	void makeNoise() { std::cout << "TarantulaWoman::makeNoise()\n"; }
	void savePersonFromFire() { std::cout << "TarantulaWoman::savePersonFromFire()\n"; }
	void move() { std::cout << "TarantulaWoman::move()\n"; }
};

template <class Animal, class FlyAbility>
void animalSound(Animal* a, FlyAbility* f) {
	a->makeNoise();
	a->move();
	f->flyOuttaThere();
}

template <class SuperHero, class KillAbility>
void saveFromFire(SuperHero* s, KillAbility* k) {
	s->savePersonFromFire();
	s->move();
	k->killThemAll();
}


int main() {

	Amoeba am;
	TarantulaWoman tw;
	SuperlativeMan sm;
	FlyAbility fa;
	KillAbility ka;

	animalSound(&am, &fa);
	animalSound(&tw, &fa);

	saveFromFire(&am, &ka);
	saveFromFire(&tw, &ka);
	saveFromFire(&sm, &ka);


return 0;
}
