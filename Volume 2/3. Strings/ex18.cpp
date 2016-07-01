/*
Prove to yourself that the at( ) member function really
will throw an exception if an attempt is made to go out
of bounds, and that the indexing operator ([ ]) won’t.
*/

#include <iostream>
#include <string>
#include <stdexcept>

int main() {

	try {
		std::string str = "Test";
		//str[10] = 'Z';
		str.at(10) = 'Z';
	}
	catch (const std::out_of_range& e) {
		std::cout << "Exception detected: " << e.what() << '\n';
	}

return 0;
}
