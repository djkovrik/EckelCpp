/*
Create a class with member functions that throw exceptions.
Within this class, make a nested class to use as an exception
object. It takes a single const char* as its argument; this
represents a description string. Create a member function
that throws this exception. (State this in the function’s
exception specification.) Write a try block that calls this
function and a catch clause that handles the exception by
displaying its description string.
*/

#include <iostream>

class MyClass {
public:
	class MyException  {
	public:
		MyException(const char* msg) : data(msg) {}
		const char* what() const { return data; }
	private:
		const char* data;
	};

	void func() throw (MyException) {
		throw MyException("This is an exception from MyClass::func()");
	}
};

int main() {

	try {
		MyClass m;
		m.func();
	}
	catch (MyClass::MyException& ex) {
		std::cout << "Exception detected: " << ex.what() << '\n';
	}

return 0;
}
