/*
Continuing with the previous exercise, add an eatFood( )
member function to both SuperlativeMan and Amoeba
(but not SuperlativeAmoeba), such that the two versions of eatFood( )
take different types of food objects (so the signatures of the two
functions differ). What must you do in SuperlativeAmoeba to call
either eatFood( ) function? Why?

Exercise 9:
Continuing with the previous exercise, add an integer
strengthFactor data member to SuperHero from exercise 4,
along with a constructor to initialize it. Add constructors
in the three derived classes to initialize strengthFactor as
well. What must you do differently in SuperlativeAmoeba?

Exercise 8:
Dropping the Animal interface from exercise 4,
redefine Amoeba to only implement SuperHero. Now
define a SuperlativeAmoeba class that inherits from
both SuperlativeMan and Amoeba. Try to pass a SuperlativeAmoeba
object to saveFromFire( ). What do you have to do to
make this legal? How does using virtual inheritance
change the size of your objects?

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

class SuperHero {
public:
	SuperHero(int s) : strengthFactor(s) {}
	virtual void savePersonFromFire() = 0;
	virtual void move() = 0;
	virtual ~SuperHero() {}
private:
	int strengthFactor;
};

class SuperlativeMan : virtual public SuperHero {
public:
	SuperlativeMan(int x) : SuperHero(x) {}
	void savePersonFromFire() { std::cout << "SuperlativeMan::savePersonFromFire()\n"; }
	void move() { std::cout << "SuperlativeMan::move()\n"; }
	void eatFood(int f) { std::cout << "SuperlativeMan::eatFood(int)\n"; }
};

class Amoeba : virtual public SuperHero {
public:
	Amoeba(int x) : SuperHero(x) {}
	void savePersonFromFire() { std::cout << "Amoeba::savePersonFromFire()\n"; }
	void move() { std::cout << "Amoeba::move()\n"; }
	void eatFood() { std::cout << "Amoeba::eatFood()\n"; }
};

class TarantulaWoman : public SuperHero {
public:
	TarantulaWoman(int x) : SuperHero(x) {}
	void makeNoise() { std::cout << "TarantulaWoman::makeNoise()\n"; }
	void savePersonFromFire() { std::cout << "TarantulaWoman::savePersonFromFire()\n"; }
	void move() { std::cout << "TarantulaWoman::move()\n"; }
};

class SuperlativeAmoeba : public SuperlativeMan, public Amoeba {
public:
	SuperlativeAmoeba(int x) : SuperHero(x), SuperlativeMan(x), Amoeba(x) {}
	void savePersonFromFire() { std::cout << "SuperlativeAmoeba::savePersonFromFire()\n"; }
	void move() { std::cout << "SuperlativeAmoeba::move()\n"; }

	void testFood() {
		Amoeba::eatFood();
		SuperlativeMan::eatFood(2);
	}
};

void saveFromFire(SuperHero* s) {
	s->savePersonFromFire();
	s->move();
}


int main() {

	SuperlativeAmoeba sa(10);

	saveFromFire(&sa);

	sa.testFood();

return 0;
}
