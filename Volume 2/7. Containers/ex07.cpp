/*
Use a stack<int> and populate it with a Fibonacci
sequence. The program’s command line should take
the number of Fibonacci elements desired, and you
should have a loop that looks at the last two
elements on the stack and pushes a new one for
every pass through the loop.
*/

#include <iostream>
#include <stack>

int main() {

	int n = 0;
	std::cin >> n;

	if (n < 3) {
		std::cout << 1 << '\n';
		return 0;
	}

	std::stack<int> numbers;

	int a = 1;
	int b = 1;
	int c = 0;

	numbers.push(a);
	numbers.push(b);

	for (int i = 3; i <= n; i++) {
		b = numbers.top();
		numbers.pop();

		a = numbers.top();
		numbers.pop();

		c = a + b;

		numbers.push(a);
		numbers.push(b);
		numbers.push(c);
	}

	std::cout << n << "(th) fibonacci number is: " << numbers.top() << '\n';

return 0;
}
