/*
Create three sequences of Noisy objects, a vector,
deque, and list. Sort them. Now write a function
template to receive the vector and deque sequences
as a parameter to sort them and record the sorting time.
Write a specialized template function to do the same for
list (ensure to call its member sort( ) instead of the
generic algorithm). Compare the performance of the
different sequence types.
*/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <ctime>
#include "Noisy.h"

template <typename Container>
void sort_container(Container c, std::string message = "") {
	clock_t ticks = clock();
	std::sort(c.begin(), c.end());
	std::cout << message << " timings: " << (double)(clock() - ticks) / CLOCKS_PER_SEC  << '\n';
}

template <>
void sort_container<std::list<Noisy>>(std::list<Noisy> c, std::string message) {
	clock_t ticks = clock();
	c.sort();
	std::cout << message << " timings: " << (double)(clock() - ticks) / CLOCKS_PER_SEC  << '\n';
}

int main() {

	std::vector<Noisy> nvec;
	std::deque<Noisy> ndeq;
	std::list<Noisy> nlist;

	std::generate_n(back_inserter(nvec),  100000, NoisyGen());
	std::generate_n(back_inserter(ndeq),  100000, NoisyGen());
	std::generate_n(back_inserter(nlist), 100000, NoisyGen());

	sort_container(nvec,  "vector");
	sort_container(ndeq,  "deque");
	sort_container(nlist, "list");

return 0;
}
