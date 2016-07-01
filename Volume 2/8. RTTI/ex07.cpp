/*
Create a large vector of pointers to random Shape objects.
Write a non-virtual draw( ) function in Shape that uses RTTI
to determine the dynamic type of each object and executes the
appropriate code to "draw" the object with a switch statement.
Then rewrite your Shape hierarchy the "right way", using virtual
functions. Compare the code sizes and execution times of the
two approaches.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

class ShapeBad {
public:
	virtual ~ShapeBad() {}
	void draw() const;

};

class CircleBad : public ShapeBad {
public:
	void draw_circle() const {}
};

class SquareBad : public ShapeBad {
public:
	void draw_square() const {}
};


void ShapeBad::draw() const {

	if ( typeid(*this) == typeid(CircleBad) ) {
		const CircleBad* cbp = dynamic_cast<const CircleBad*>(this);
		cbp->draw_circle();
	} else
		if ( typeid(*this) == typeid(SquareBad) ) {
				const SquareBad* sbp = dynamic_cast<const SquareBad*>(this);
				sbp->draw_square();
		}
}

class Shape {
public:
	virtual void draw() const = 0;
	virtual ~Shape() {}
};

class Circle : public Shape {
public:
	void draw() const override {}
};

class Square : public Shape {
public:
	void draw() const override {}
};

int main() {

	std::srand(std::time(0));

	const int vector_size = 10000000;

	std::vector<ShapeBad*> bad_shapes;
	bad_shapes.reserve(vector_size);

	std::vector<Shape*> shapes;
	shapes.reserve(vector_size);

	std::generate_n(std::back_inserter(bad_shapes), vector_size,
		[]()->ShapeBad* {
			if (std::rand()%2 == 0)
				return new CircleBad();
			else
				return new SquareBad();
		}
	);

	std::generate_n(std::back_inserter(shapes), vector_size,
		[]()->Shape* {
			if (std::rand()%2 == 0)
				return new Circle();
			else
				return new Square();
		}
	);

	clock_t t0 = clock(); // start

	for (const auto& element : bad_shapes)
		element->draw();

	clock_t t1 = clock(); // end

	std::cout << "RTTI calls timing: " << (double)(t1 - t0) / CLOCKS_PER_SEC  << '\n';

	t0 = clock(); // start

	for (const auto& element : shapes)
		element->draw();

	t1 = clock(); // end

	std::cout << "Polymorph calls timing: " << (double)(t1 - t0) / CLOCKS_PER_SEC  << '\n';

return 0;
}
