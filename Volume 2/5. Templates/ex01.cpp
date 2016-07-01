/*
Write a unary function template that takes a single
type template parameter. Create a full specialization
for the type int. Also create a non-template overload
for this function that takes a single int parameter.
Have your main program invoke three function variations.
*/

#include <iostream>

template <typename T>
void foo(T t) {
	std::cout << "1. template <typename T>\n   void foo(T t)" << '\n';
}

template<>
void foo(int t) {
	std::cout << "2. template<>\n   void foo(int t)" << '\n';
}

void foo(int t) {
	std::cout << "3. void foo(int t)" << '\n';
}

int main() {
	foo(2.2);
	foo<>(2);
	foo(2);

return 0;
}
