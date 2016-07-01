/*
Create a global function named drawQuad( ) that takes
a reference to a Shape object. It calls the draw( )
function of its Shape parameter if it has four sides
(that is, if it’s a Square or Rectangle). Otherwise,
it prints the message "Not a quadrilateral". Traverse a
vector of pointers to random Shapes, calling drawQuad( )
for each one. Place Squares, Rectangles, Circles and
Triangles in your vector.
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
	virtual void draw() const = 0;
	virtual ~Shape() {}
};

class Circle : public Shape {
public:
	void draw() const override { std::cout << "Circle::draw()\n"; }
};

class Triangle : public Shape {
public:
	void draw() const override { std::cout << "Triangle::draw()\n"; }
};

class Square : public Shape {
public:
	void draw() const override { std::cout << "Square::draw()\n"; }
};

class Rectangle : public Shape {
public:
	void draw() const override { std::cout << "Rectangle::draw()\n"; }
};

void drawQuad(const Shape& s) {
	if ( ( typeid(s) == typeid(Square) ) || ( typeid(s) == typeid(Rectangle) ) )
		s.draw();
	else
		std::cout << "Not a quadrilateral\n";
}

int main() {

	std::srand(std::time(0));

	std::vector<Shape*> shapes;

	std::generate_n(std::back_inserter(shapes), 25,
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

	for (const auto& s : shapes)
		drawQuad(*s);

return 0;
}
