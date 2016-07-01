/*
Prove to yourself that all exception objects (the ones
that are thrown) are properly destroyed.
*/

#include <iostream>

class Exception {
public:
	Exception() { std::cout << "Exception()\n"; }
	~Exception() { std::cout << "~Exception()\n"; }
};

int main() {

	try {
		throw Exception();
	}
	catch (Exception& e){
		std::cout << "Exception detected!\n";
	}

return 0;
}
