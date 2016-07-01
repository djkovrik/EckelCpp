/*
Write a generic main( ) that takes all exceptions and
reports them as errors.
*/

#include <iostream>
#include <stdexcept>

int main() {

	try {
		std::cout << "Throwing some exception...\n";
		throw std::runtime_error("Dumb exception");
	}
	catch(...) {
		std::cout << "Some exception detected!\n";
	}

return 0;
}
