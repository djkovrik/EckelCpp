/*
Create a class hierarchy with a base class B
and a derived class D. Put a virtual member
function void f( ) in B such that it will print
a message indicating that B’s f( ) was called,
and redefine this function for D to print a
different message. Create a vector<B*>, and
fill it with B and D objects. Use for_each( )
to call f( ) for each of the objects in your vector.
*/

#include <iostream>
#include <algorithm>
#include <vector>

class B {
public:
	virtual void f() const { std::cout << "B::f()\n"; }
	virtual ~B() = default;
};

class D : public B {
public:
	void f() const override { std::cout << "D::f()\n"; }
};

int main() {

	std::vector<B*> v;

	B b1, b2;
	D d1, d2;

	v.push_back(&b1);
	v.push_back(&d1);
	v.push_back(&b2);
	v.push_back(&d2);

	std::for_each(v.begin(), v.end(),
			[](const B* ptr) { ptr->f(); }
	);

return 0;
}
