/*
Create a class that has an operator< and an ostream& operator<<.
The class should contain a priority number. Create a generator for
your class that makes a random priority number. Fill a priority_queue
using your generator, and then pull the elements out to show they are
in the proper order.
*/

#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

class MyClass {
public:
	MyClass(int d, int p) : data(d), priority(p) {}
	int data;
	int priority;
};

std::ostream& operator<<(std::ostream& out, const MyClass& m) {
	out << "Data: " << m.data << ", priority: " << m.priority;
	return out;
}

bool operator<(const MyClass& left, const MyClass& right) {
	return left.priority < right.priority;
}

int main() {

	std::srand(std::time(0));

	std::priority_queue<MyClass> mpq;

	for (int i = 1; i <= 10; ++i)
		mpq.push( MyClass(i*2, std::rand()%100 + 1) );

	while (mpq.size() != 0) {
		std::cout << mpq.top() << '\n';
		mpq.pop();
	}

return 0;
}
