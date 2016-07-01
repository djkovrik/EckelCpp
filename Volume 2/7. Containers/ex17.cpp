/*
Compare the performance of stack based on whether it
is implemented with vector, deque, or list.
*/

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <ctime>

struct SomeBigType {
	char chars[10000];
	int ints[10000];
	long longs[10000];
};

template<typename T, typename Container, size_t size = 10000>
void test_stack(std::string message) {

	std::stack<T, Container> test;
	T element;

	clock_t t0 = clock();
	for (size_t i = 0; i < size; i++)
		test.push(element);

	clock_t t1 = clock();
	std::cout << message << " timing: " << (double)(t1 - t0) / CLOCKS_PER_SEC  << '\n';
}

int main() {

	test_stack<SomeBigType, std::deque<SomeBigType>>("deque");
	test_stack<SomeBigType, std::vector<SomeBigType>>("vector");
	test_stack<SomeBigType, std::list<SomeBigType>>("list");

return 0;
}
