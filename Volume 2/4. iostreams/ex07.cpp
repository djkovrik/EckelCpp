/*
String streams accommodate easy conversions, but they
come with a price. Write a program that races atoi( )
against the stringstream conversion system to see the
effect of the overhead involved with stringstream.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>

int main() {

	const int size = 1000000;

	std::vector<std::string> numbers;
	numbers.reserve(size);

	for (int i = 1; i <= size; i++) {
		std::stringstream ss;
		ss << i;
		numbers.push_back( ss.str() );
	}

	std::cout << "vector has been created, size: " << numbers.size() << ". Starting comparison...\n";

	std::cout << "   stringstream conversion: ";

	long sum = 0;
	clock_t t0 = clock();

	for (size_t i = 0; i < numbers.size(); i++) {
		std::stringstream ss(numbers[i]);
		int x = 0;
		ss >> x;
		sum += x;
	}

	clock_t t1 = clock();
	std::cout << (double)(t1 - t0) / CLOCKS_PER_SEC  << '\n';

	std::cout << "   atoi conversion: ";
	sum = 0;
	t0 = clock();

	for (size_t i = 0; i < numbers.size(); i++) {
		int x = atoi(numbers[i].c_str());
		sum += x;
	}
	t1 = clock();
	std::cout << (double)(t1 - t0) / CLOCKS_PER_SEC  << '\n';

return 0;
}
