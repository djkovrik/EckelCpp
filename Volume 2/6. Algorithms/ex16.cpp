/*
Test the speed of your computer. Call srand(time(0)),
then make an array of random numbers. Call srand(time(0))
again and generate the same number of random numbers
in a second array. Use equal( ) to see if the arrays
are the same. (If your computer is fast enough,
time(0) will return the same value both times it is
called.) If the arrays are not the same, sort them
and use mismatch( ) to see where they differ. If they
are the same, increase the length of your array and try again.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <ctime>
#include <limits>

int main() {

	const int array_size = 90000000;
	std::vector<int> v1(array_size);
	std::vector<int> v2(array_size);

	srand(time(0));
	std::generate_n(v1.begin(), array_size, []() { return std::rand() % 100; });

	srand(time(0));
	std::generate_n(v2.begin(), array_size, []() { return std::rand() % 100; });


	std::cout << "Arrays are ";
	if ( std::equal(v1.begin(), v1.end(), v2.begin()) )
		std::cout << "equal!\n";
	else
		std::cout << "not equal!\n";

	auto p = std::mismatch(v1.begin(), v1.end(), v2.begin());

	std::cout << "Mistmatched pair: " << *p.first << " - " << *p.second << '\n';

return 0;
}
