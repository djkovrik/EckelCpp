/*
Create a destructor that throws an exception, and write
code to prove to yourself that this is a bad idea by showing
that if a new exception is thrown before the handler for the
existing one is reached, terminate( ) is called.
*/

#include <iostream>

class Exception1 {};
class Exception2 {};

class MyClass{
public:
	MyClass() { std::cout << "MyClass()" << '\n'; }

    ~MyClass() {
    	std::cout << "~MyClass()" << '\n';
        throw Exception2();
    }
};

int main() {

    try {
    	throw Exception1();
    }

    catch (Exception1&) {
        MyClass m;
    }

return 0;
}
