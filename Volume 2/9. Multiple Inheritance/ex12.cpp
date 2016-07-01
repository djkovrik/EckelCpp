/*
Remove SuperlativeAmoeba from your hierarchy
and modify Amoeba to derive from both SuperlativeMan
(which still derives from SuperHero) and SuperHero.
Implement a virtual workout( ) function in both
SuperHero and SuperlativeMan (with identical signatures),
and call it with a Amoeba object. Which function gets called?
*/

#include <iostream>


class SuperHero {
public:
	virtual void savePersonFromFire() = 0;
	virtual void move() = 0;
	virtual ~SuperHero() {}
	void workout() { std::cout << "SuperHero::workout()\n"; }
};

class SuperlativeMan : virtual public SuperHero {
public:
	void savePersonFromFire() { std::cout << "SuperlativeMan::savePersonFromFire()\n"; }
	void move() { std::cout << "SuperlativeMan::move()\n"; }
	void workout() { std::cout << "SuperlativeMan::workout()\n"; }
};

class Amoeba : virtual public SuperHero, public SuperlativeMan {
public:
	void savePersonFromFire() { std::cout << "Amoeba::savePersonFromFire()\n"; }
	void move() { std::cout << "Amoeba::move()\n"; }
};


int main() {

	Amoeba a;
	a.workout();

return 0;
}
