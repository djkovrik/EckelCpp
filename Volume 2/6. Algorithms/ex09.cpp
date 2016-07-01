/*
Write a program that takes an integer as a command
line argument and finds all of its factors.
*/

#include <iostream>

int main() {

		int x = 0;
		std::cin >> x;

		for (int i = 2; i <= x; ++i) {
		    while (x % i == 0) {
		        x /= i;
		        std::cout << i << '\n';
		    }
		}

return 0;
}
