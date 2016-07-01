/*
Starting with the results of Exercise 1, create a
pointer to an X called px and assign to it the address
of the object of type A you created before. Fix the
problem using a virtual base class. Now fix X so you no
longer have to call the constructor for X inside A.

Exercise 1:
Create a base class X with a single constructor that
takes an int argument and a member function f( ), which
takes no arguments and returns void. Now derive Y and Z
from X, creating constructors for each of them that take
a single int argument. Next, derive A from Y and Z.
Create an object of class A, and call f( ) for that
object. Fix the problem with explicit disambiguation.
*/

#include <iostream>

class X {
public:
	X(int xxx = 0) : x(xxx) {}
	void f() { std::cout << "X::f()\n"; }
private:
	int x;
};

class Y : virtual public X {
public:
	Y(int yyy) : X(yyy), y(yyy) {}
private:
	int y;
};

class Z : virtual public X {
public:
	Z(int zzz) : X(zzz), z(zzz) {}
private:
	int z;
};

class A : public Y, public Z {
public:
	A(int aaa) : Y(aaa), Z(aaa), a(aaa) {}
private:
	int a;
};

int main() {

	A a(1);

	X* px = &a;
	px->f();


return 0;
}
