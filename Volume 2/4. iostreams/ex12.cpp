/*
Discover the maximum number of digits of precision your
implementation of iostreams will print by repeatedly
increasing the value of the argument to precision( )
when printing a transcendental number such as sqrt(2.0).
*/

#include <iostream>
#include <cmath>
#include <limits>

int main() {

	for (int i = 0; i < 45; i++) {
		std::cout.precision(i);
		std::cout << i << ": " << sqrt(2.0) << '\n';
	}

return 0;
}
