/*
Create a vector of pointers to 10 random Shape objects
(at least Squares and Circles, for example). The draw( )
member function should be overridden in each concrete
class to print the dimensions of the object being drawn
(the length or the radius, whichever applies). Write a
main( ) program that draws all the Squares in your container
first, sorted by length, and then draws all Circles,
sorted by radius.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

class Shape {
public:
	virtual void draw() const = 0;
	virtual ~Shape() = default;
};

class Square : public Shape {
public:
	Square(double p) : perimeter(p) {}
	void draw() const override { std::cout << "Square perimeter: " << perimeter << '\n'; }
	bool operator<(const Square& other) { return perimeter < other.perimeter; }
private:
	double perimeter;
};

class Circle : public Shape {
public:
	Circle(double r) : radius(r) {}
	void draw() const override { std::cout << "Circle radius: " << radius << '\n'; }
	bool operator<(const Circle& other) { return radius < other.radius; }
private:
	double radius;
};


int main() {

	std::srand(std::time(0));

	std::vector<Shape*> vs;

	std::generate_n(std::back_inserter(vs), 10,
		[]() ->Shape* {

			double temp = static_cast<double>( (std::rand()%100 + 1) / 10.0 );

			if ( std::rand() % 2 == 0)
				return new Square(temp);
			else
				return new Circle(temp);
		}
	);

	std::vector<Square*> vsq;
	std::vector<Circle*> vcr;

	std::cout << "Initial vector:\n";

	for (const auto& v : vs) {
		v->draw();

		Square* sq = dynamic_cast<Square*>(v);

		if (sq) {
			vsq.push_back(sq);
			continue;
		}

		Circle* cr = dynamic_cast<Circle*>(v);

		if (cr)
			vcr.push_back(cr);
	}

	vs.clear();

	std::sort(vsq.begin(), vsq.end(),
		[](Square* a, Square* b) { return *a < *b; }
	);

	std::sort(vcr.begin(), vcr.end(),
		[](Circle* a, Circle* b) { return *a < *b; }
	);


	for (const auto& element : vsq)
		vs.push_back(element);

	for (const auto& element : vcr)
		vs.push_back(element);

	vcr.clear(); vsq.clear();

	std::cout << "\nSorted vector:\n";

	for (const auto& v : vs)
		v->draw();


return 0;
}
