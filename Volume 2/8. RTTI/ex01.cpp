/*
Create a Base class with a virtual destructor and a
Derived class that inherits from Base. Create a vector
of Base pointers that point to Base and Derived objects
randomly. Using the contents your vector, fill a second
vector with all the Derived pointers. Compare execution
times between typeid( ) and dynamic_cast to see which is
faster.
*/

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>

class Base {
public:
	virtual ~Base() {}
};

class Derived : public Base {};

int main() {

	std::srand(std::time(0));

	std::vector<Base*> bvec;

	std::generate_n(std::back_inserter(bvec), 10000000,
		[]() -> Base* {
			if (std::rand()%2 == 0)
				return new Base();
			else
				return new Derived();
		}
	);

	std::cout << "vector<Base*> created, size: " << bvec.size() << '\n';

	std::vector<Derived*> dvec_cast;

	clock_t t0 = clock(); // start

	for (auto ptr : bvec) {
		Derived* dptr = dynamic_cast<Derived*>(ptr);

		if (dptr)
			dvec_cast.push_back(dptr);
	}

	clock_t t1 = clock(); // end

	std::cout << "\nFirst vector<Derived*> created, size: " << dvec_cast.size();
	std::cout << "\ndynamic_cast timings: " << (double)(t1 - t0) / CLOCKS_PER_SEC  << '\n';

	std::vector<Derived*> dvec_info;

	t0 = clock(); // start

	for (auto ptr : bvec) {
		if (typeid(Derived) == typeid(*ptr))
			dvec_info.push_back((Derived*)ptr);
	}

	t1 = clock(); // end

	std::cout << "\nSecond vector<Derived*> created, size: " << dvec_info.size();
	std::cout << "\ntypeinfo timings: " << (double)(t1 - t0) / CLOCKS_PER_SEC  << '\n';

return 0;
}
