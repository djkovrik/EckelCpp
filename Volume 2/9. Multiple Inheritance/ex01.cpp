/*
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
	X(int xxx) : x(xxx) {}
	void f() { std::cout << "X::f()\n"; }
private:
	int x;
};

class Y : public X {
public:
	Y(int yyy) : X(yyy), y(yyy) {}
	void f() { std::cout << "Y::f()\n"; }
private:
	int y;
};

class Z : public X {
public:
	Z(int zzz) : X(zzz), z(zzz) {}
	void f() { std::cout << "Z::f()\n"; }
private:
	int z;
};

class A : public Y, public Z {
public:
	using Z::f;
	A(int aaa) : Y(aaa), Z(aaa), a(aaa) {}
private:
	int a;
};

int main() {

	A a(1);
	a.f();

return 0;
}
