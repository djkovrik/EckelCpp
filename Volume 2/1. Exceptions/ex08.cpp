/*
Prove to yourself that if you create an exception object
on the heap and throw the pointer to that object, it will
not be cleaned up.
*/

#include <iostream>

class Exception {
public:
	Exception() { std::cout << "Exception()\n"; }
	~Exception() { std::cout << "~Exception()\n"; }
};

int main() {

	try {
		Exception* exc = new Exception();
		throw exc;
	}
	catch (Exception* e){
		std::cout << "Exception detected!\n";
	}

return 0;
}
