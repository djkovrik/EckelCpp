/*
Write a program to compare the speed of sorting a list
using list::sort( ) vs. using std::sort( ) (the STL
algorithm version of sort( )).
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <list>

int main() {
	std::list<int> list1;
	std::list<int> list2;

	std::generate_n(back_inserter(list1), 100000, []() { return std::rand()%1000 + 1; });
	std::generate_n(back_inserter(list2), 100000, []() { return std::rand()%1000 + 1; });

	clock_t ticks = clock();
	list1.sort();
	std::cout << "list::sort() timings: " << (double)(clock() - ticks) / CLOCKS_PER_SEC  << '\n';

	ticks = clock();
	//!std::sort(list2.begin(), list2.end());
	//!Not possible! std::sort requires RandomAccessIterator
	std::cout << "std::sort() timings: " << (double)(clock() - ticks) / CLOCKS_PER_SEC  << '\n';

return 0;
}
