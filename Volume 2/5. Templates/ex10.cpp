/*
Write a class template that takes two type parameters.
Define a partial specialization for the first parameter,
and another partial specialization that specifies the
second parameter. In each specialization, introduce
members that are not in the primary template.
*/

#include <iostream>
#include <string>

template<typename A, typename B>
class X {
public:
	void f() { std::cout << "Primary template.\n"; }
};

template<typename A>
class X<A, double> {
public:
	void f() { std::cout << "B = double.\n"; }
};

template<typename B>
class X<char, B> {
public:
	void f() { std::cout << "A = char.\n"; }
};


int main() {

	X<short,long>().f();
	X<int,double>().f();
	X<char,bool>().f();

return 0;
}
