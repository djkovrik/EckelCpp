/*
Modify VirtualConstructor.cpp to use a map instead of
if-else statements inside Shape::Shape(string type).
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include <stdexcept>
#include <cstddef>
#include <vector>
#include <map>
#include "purge.h"

using namespace std;

class Shape {
	Shape* s;
	map<string, Shape*> shapes;
	// Prevent copy-construction & operator=
	Shape(Shape&);
	Shape operator=(Shape&);
protected:
	Shape() { s = 0; }
public:
	virtual void draw() { s->draw(); }
	virtual void erase() { s->erase(); }
	virtual void test() { s->test(); }
	virtual ~Shape() {
		cout << "~Shape" << endl;
		if(s) {
			cout << "Making virtual call: ";
			s->erase(); // Virtual call
		}
		cout << "delete s: ";
		delete s; // The polymorphic deletion
		// (delete 0 is legal; it produces a no-op)
	}
	class BadShapeCreation : public logic_error {
	public:
		BadShapeCreation(string type)
		: logic_error("Cannot create type " + type) {}
	};
	Shape(string type) throw(BadShapeCreation);
};

class Circle : public Shape {
	Circle(Circle&);
	Circle operator=(Circle&);
	Circle() {} // Private constructor
	friend class Shape;
public:
	void draw() { cout << "Circle::draw" << endl; }
	void erase() { cout << "Circle::erase" << endl; }
	void test() { draw(); }
	~Circle() { cout << "Circle::~Circle" << endl; }
};

class Square : public Shape {
	Square(Square&);
	Square operator=(Square&);
	Square() {}
	friend class Shape;
public:
	void draw() { cout << "Square::draw" << endl; }
	void erase() { cout << "Square::erase" << endl; }
	void test() { draw(); }
	~Square() { cout << "Square::~Square" << endl; }
};

Shape::Shape(string type) throw(Shape::BadShapeCreation) {

	shapes["Circle"] = new Circle;
	shapes["Square"] = new Square;

	if(shapes.find(type) != shapes.end())
		s = shapes[type];
	else
		throw BadShapeCreation(type);

	draw();	// Virtual call in the constructor
}

char* sl[] = { "Circle", "Square", "Square",
	"Circle", "Circle", "Circle", "Square" };

int main() {
	vector<Shape*> shapes;
	cout << "virtual constructor calls:" << endl;
	try {
		for(size_t i = 0; i < sizeof sl / sizeof sl[0]; i++)
			shapes.push_back(new Shape(sl[i]));
	} catch(Shape::BadShapeCreation& e) {
		cout << e.what() << endl;
		purge(shapes);
		return EXIT_FAILURE;
	}
	for(size_t i = 0; i < shapes.size(); i++) {
		shapes[i]->draw();
		cout << "test" << endl;
		shapes[i]->test();
		cout << "end test" << endl;
		shapes[i]->erase();
	}
	Shape c("Circle"); // Create on the stack
	cout << "destructor calls:" << endl;
	purge(shapes);
} ///:~
