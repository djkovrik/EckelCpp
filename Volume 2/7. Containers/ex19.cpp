/*
Generate a sequence of random integers, storing them
into an array of int. Initialize a valarray<int> with
its contents. Compute the sum, minimum value, maximum
value, average, and median of the integers using valarray
operations.
*/

#include <iostream>
#include <valarray>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int main() {

	std::srand(std::time(0));

	const size_t array_size = 10;
	int array[array_size] = {0};

	for (int& a : array)
		a = std::rand()%100 + 1;

	std::valarray<int> varray(array, array_size);

	for (auto i : varray)
		std::cout << i << ' ';

	std::cout << "\nSum: " << varray.sum()
			  << "\nMin: " << varray.min()
			  << "\nMax: " << varray.max()
			  << "\nAverage: " << varray.sum() / varray.size()
			  << "\nMedian: ";

	std::nth_element(std::begin(varray), std::begin(varray) + array_size/2, std::begin(varray) + array_size);
	std::cout << varray[varray.size()/2] << '\n';


return 0;
}
