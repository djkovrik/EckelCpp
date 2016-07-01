/*
Modify BreakTie.cpp by adding a class named VeryBottom
that derives (non-virtually) from Bottom. VeryBottom
should look just like Bottom except change "Left" to "Right"
in the using declaration for f. Change main( ) to instantiate
a VeryBottom instead of a Bottom object. Which f( ) gets called?
*/

#include <iostream>

class Top {
public:
	virtual ~Top() {}
};

class Left : virtual public Top {
public:
	void f() { std::cout << "Left::f()\n"; }
};

class Right : virtual public Top {
public:
	void f() { std::cout << "Right::f()\n"; }
};

class Bottom : public Left, public Right {
public:
	using Left::f;
};

class VeryBottom : public Bottom {
public:
	using Right::f;
};


int main() {
	//Bottom b;
	VeryBottom b;
	b.f();
}
