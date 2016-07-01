/*
Sort a vector of random Shape objects by class name.
Use type_info::before( ) as the comparison function for sorting.
*/

#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstdlib>
#include <ctime>

class Shape {
public:
	virtual void what() const = 0;
	virtual ~Shape() {}
};

class Circle : public Shape {
public:
	void what() const override { std::cout << "This is Circle\n"; }
};

class Triangle : public Shape {
public:
	void what() const override { std::cout << "This is Triangle\n"; }
};

class Square : public Shape {
public:
	void what() const override { std::cout << "This is Square\n"; }
};

class Rectangle : public Shape {
public:
	void what() const override { std::cout << "This is Rectangle\n"; }
};


int main() {

	std::srand(std::time(0));

	std::vector<Shape*> shapes;

	std::generate_n(std::back_inserter(shapes), 15,
		[]() ->Shape* {
			int temp = std::rand() % 4;

			if (temp == 0)
				return new Circle();
			else if (temp == 1)
				return new Triangle();
			else if (temp == 2)
				return new Square();
			else
				return new Rectangle();
		}
	);

	std::cout << "Initial vector:\n";

	for (const auto& s : shapes)
		s->what();

	std::sort(shapes.begin(), shapes.end(),
		[](const Shape* a, const Shape* b) {
			return typeid(*a).before(typeid(*b));
		}
	);

	std::cout << "\nSorted vector:\n";

	for (const auto& s : shapes)
		s->what();

return 0;
}
