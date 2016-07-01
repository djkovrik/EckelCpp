/**
Create a makefile for one of the previous exercises (of your choice) that allows you
to type make for a production build of the program, and make debug for a build of the
program including debugging information.
**/

/*
Write a program that uses two nested for loops and the modulus
operator (%) to detect and print prime numbers (integral numbers
that are not evenly divisible by any other numbers except for themselves and 1).
*/

#include <iostream>

using namespace std;

int main() {

	#ifdef DEBUG
		cout << "Debug version." << endl;
	#endif // DEBUG

	const int limit = 100;
	int counter;

	for (int number = 1; number < limit; number++) {

		counter = 0;

		for (int i = 1; i <= number; i++)
			if (number % i == 0)
				++counter;

		if (2 == counter)
			cout << number << " ";
	}

return 0;
}
