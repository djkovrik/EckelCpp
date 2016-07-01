/*
Write templates that take non-type parameters
of the following variety: an int, a pointer to
an int, a pointer to a static class member of
type int, and a pointer to a static member function.
*/

#include <iostream>

class X {
public:
	static void f() { std::cout << "static X::f() called.\n"; }
	static float x;
};

float X::x = 123.456;
int global_x = 321;

template <int i>
void foo1() { std::cout << "template <int i> void foo1() called, i = " << i << '\n'; }

template <int* i>
void foo2() { std::cout << "template <int* i> void foo2() called, *i = " << *i << '\n'; }

template <float* f>
void foo3() { std::cout << "template <float* f> void foo3() called, *f = " << *f << '\n'; }

typedef void (*fptr)();
template <fptr f>
void foo4() { std::cout << "template <void (X::*fptr)()> void foo3() called\n"; f(); }

int main() {

	foo1<123>();		// int
	foo2<&global_x>();	// pointer to int
	foo3<&X::x>();		// pointer to static class member
	foo4<&X::f>();		// pointer to static class function

return 0;
}
