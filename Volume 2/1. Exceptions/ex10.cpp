/*
Modify your solution to the previous exercise to throw
a double from the function, violating the exception
specification. Catch the violation with your own unexpected
handler that displays a message and exits the program gracefully
(meaning abort( ) is not called).

Previous exercise:
Write a function with an exception specification that
can throw four exception types: a char, an int, a bool,
and your own exception class. Catch each in main( ) and
verify the catch. Derive your exception class from a
standard exception. Write the function in such a way that
the system recovers and tries to execute it again.
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <exception>
#include <cstdlib>

class Exception : public std::runtime_error {
public:
	explicit Exception(const std::string& s) : runtime_error(s) {}
};

int menu() {

	std::cout << "\nChoose an exception type: "
			  << "\n1. char"
			  << "\n2. int"
			  << "\n3. bool"
			  << "\n4: user defined type"
			  << "\n5: double (unexpected exception)"
			  << "\nOther: close program\n";
	int x;
	std::cin >> x;

	return x;
}

void foo(bool& flag) throw (char, int, bool, Exception) {

	auto x = menu();

	switch (x) {
		case 1:
			throw char();
		case 2:
			throw int();
		case 3:
			throw bool();
		case 4:
			throw Exception("My exception");
		case 5:
			throw double();
		default:
			flag = false;
			break;
	}
}

void unexpected_handler() {
  std::cout << "Unexpected exception detected.\n";
  std::exit(0);
}

int main() {

	std::set_unexpected(unexpected_handler);

	bool try_again = true;

	while (try_again)
		try {
			foo(try_again);
		}

	catch (char& c) {
		std::cout << "char exception type has been caught.\n";
	}
	catch (int& i) {
		std::cout << "int exception type has been caught.\n";
	}
	catch (bool& b) {
		std::cout << "bool exception type has been caught.\n";
	}
	catch (Exception& e) {
		std::cout << "user defined exception type has been caught.\n";
	}

	std::cout << "Terminating program...\n";

return 0;
}


