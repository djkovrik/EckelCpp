/*
Use RTTI to assist in program debugging by printing
out the exact name of a template using typeid( ).
Instantiate the template for various types and see
what the results are.
*/

#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

template <typename A, typename B, typename C>
struct Bunch {
	A a;
	B b;
	C c;
};

struct Abstract {};

int main() {

	Bunch<int, float, double> b1;
	Bunch<char, bool, long> b2;
	Bunch<std::string, std::vector<int>, Abstract> b3;

	std::cout << typeid(b1).name() << '\n'
			  << typeid(b2).name() << '\n'
			  << typeid(b3).name() << '\n';

return 0;
}
