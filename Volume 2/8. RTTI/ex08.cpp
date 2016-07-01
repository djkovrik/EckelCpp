/*
Create a hierarchy of Pet classes, including Dog, Cat,
and Horse. Also create a hierarchy of Food classes:
Beef, Fish, and Oats. The Dog class has a member function,
eat( ), that takes a Beef parameter, likewise, Cat::eat( )
takes a Fish object, and Oats objects are passed to Horse::eat( ).
Create a vector of pointers to random Pet objects, and visit
each Pet, passing the correct type of Food object to its eat( ) function.
*/

#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstdlib>
#include <ctime>

class Food {
public:
	virtual std::string what() const { return "Food"; }
	virtual ~Food() {}
};

class Beef : public Food {
public:
	std::string what() const override { return "Beef"; }
};

class Fish : public Food {
public:
	std::string what() const override { return "Fish"; }
};

class Oats : public Food {
public:
	std::string what() const override { return "Oats"; }
};

class Pet {
public:
	virtual void eat(Food f) const { std::cout << "Pet eats " << f.what() << '\n'; }
	virtual ~Pet() {}
};

class Dog : public Pet {
public:
	void eat(Beef b) const { std::cout << "Dog eats " << b.what() << '\n'; }
};

class Cat : public Pet {
public:
	void eat(Fish f) const { std::cout << "Cat eats " << f.what() << '\n'; }
};

class Horse : public Pet {
public:
	void eat(Oats o) const { std::cout << "Horse eats " << o.what() << '\n'; }
};

int main() {

	std::srand(std::time(0));

	std::vector<Pet*> pets;

	std::generate_n(std::back_inserter(pets), 20,
		[]() ->Pet* {
			int temp = std::rand() % 3;

			if (temp == 0)
				return new Dog();
			else if (temp == 1)
				return new Cat();
			else
				return new Horse();
		}
	);

	Beef b;
	Fish f;
	Oats o;

	for (const auto& pet : pets) {
		Dog* dp = dynamic_cast<Dog*>(pet);
		Cat* cp = dynamic_cast<Cat*>(pet);
		Horse* hp = dynamic_cast<Horse*>(pet);

		if (dp) dp->eat(b);
		else if (cp) cp->eat(f);
		else if (hp) hp->eat(o);
	}

return 0;
}
