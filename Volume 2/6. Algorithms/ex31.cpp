/*
Generate an arbitrary number of random numbers in a
stack-based array. Use max_element( ) to find the
largest number in array. Swap it with the number at
the end of your array. Find the next largest number
and place it in the array in the position before the
previous number. Continue doing this until all elements
have been moved. When the algorithm is complete, you
will have a sorted array. (This is a "selection sort".)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {

	std::srand(std::time(0));

	std::vector<int> numbers(25);
	std::generate(numbers.begin(), numbers.end(),[]() { return std::rand() % 100 + 1; });

	std::cout << "Initial vector: ";
	for (auto n : numbers)
		std::cout << n << ' ';

	for (size_t i = 0; i < numbers.size(); i++) {
		auto p = std::max_element(numbers.begin(), numbers.end() - i);
		std::iter_swap(p, numbers.end() - i - 1);
	}

	std::cout << "\nSorted vector : ";
	for (auto n : numbers)
		std::cout << n << ' ';


return 0;
}
