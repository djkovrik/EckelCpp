/*
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
		default:
			flag = false;
			break;
	}
}

int main() {

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


