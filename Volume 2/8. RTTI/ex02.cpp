/*
Modify C16:AutoCounter.h in Volume 1 of this book so
that it becomes a useful debugging tool. It will be
used as a nested member of each class that you are
interested in tracing. Turn AutoCounter into a template
that takes the class name of the surrounding class as
the template argument, and in all the error messages
use RTTI to print the name of the class.
*/

#include "AutoCounter.h"

class Base {
public:
	Base() : acb(this) {}
private:
	AutoCounter<Base> acb;
};

class Derived : public Base {
public:
	Derived() : acd(this) {}
private:
	AutoCounter<Derived> acd;
};

int main() {

	Base b;
	Derived d;

return 0;
}
