/*
Define a class template named Bob that takes a
single type parameter. Make Bob a friend of all
instances of a template class named Friendly,
and a friend of a class template named Picky
only when the type parameter of Bob and Picky
are identical. Give Bob member functions that
demonstrate its friendship.
*/

#include <iostream>
#include <string>
#include <typeinfo>

template <typename T> class Bob;

template <typename T>
class Friendly {
	template <typename Y>
	friend class Bob;
	std::string str = "Friendly private string";
};

template <typename T>
class Picky {
	friend class Bob<T>;
	std::string str = "Picky private string";
};

template <typename T>
class Bob {
public:

	template <typename Y>
	void foo(const Friendly<Y>& f) {
		std::cout << f.str << " for " << typeid(f).name() << '\n';
	}

	template <typename Z>
		void poo(const Picky<Z>& p) {
			std::cout << p.str << " for " << typeid(p).name() << '\n';
		}
};

int main() {

	Bob <std::string> b;

	// Bob is a friend of all Friendly instances
	Friendly<std::string> f1;
	Friendly<int> f2;

	b.foo(f1);
	b.foo(f2);

	// Bob is a friend only for Picky<std::string>
	Picky<std::string> p1;
	Picky<int> p2;

	b.poo(p1);

	//!b.poo(p2);
	//! 'std::string Picky<int>::str' is private

return 0;
}
