/*
Add a class Triangle to ShapeFactory1.cpp.
*/
#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <string>
#include <vector>
#include "purge.h"

using namespace std;

class Shape {
public:
	virtual void draw() = 0;
	virtual void erase() = 0;
	virtual ~Shape() {}
	class BadShapeCreation : public logic_error {
	public:
		BadShapeCreation(string type)
		: logic_error("Cannot create type " + type) {}
	};
	static Shape* factory(const string& type)
		throw(BadShapeCreation);
};

class Circle : public Shape {
	Circle() {} // Private constructor
	friend class Shape;
public:
	void draw() { cout << "Circle::draw" << endl; }
	void erase() { cout << "Circle::erase" << endl; }
	~Circle() { cout << "Circle::~Circle" << endl; }
};

class Square : public Shape {
	Square() {}
	friend class Shape;
public:
	void draw() { cout << "Square::draw" << endl; }
	void erase() { cout << "Square::erase" << endl; }
	~Square() { cout << "Square::~Square" << endl; }
};

class Triangle : public Shape {
	Triangle() {}
	friend class Shape;
public:
	void draw() { cout << "Triangle::draw" << endl; }
	void erase() { cout << "Triangle::erase" << endl; }
	~Triangle() { cout << "Triangle::~Square" << endl; }
};

Shape* Shape::factory(const string& type)
	throw(Shape::BadShapeCreation) {
	if(type == "Circle") return new Circle;
	if(type == "Square") return new Square;
	if(type == "Triangle") return new Triangle;
	throw BadShapeCreation(type);
}

char* sl[] = { "Circle", "Square", "Square",
	"Circle", "Triangle", "Circle", "Triangle" };

int main() {
	vector<Shape*> shapes;
	try {
		for(size_t i = 0; i < sizeof sl / sizeof sl[0]; i++)
			shapes.push_back(Shape::factory(sl[i]));
	} catch(Shape::BadShapeCreation& e) {
		cout << e.what() << endl;
		purge(shapes);
		return EXIT_FAILURE;
	}
	for(size_t i = 0; i < shapes.size(); i++) {
		shapes[i]->draw();
		shapes[i]->erase();
	}
	purge(shapes);
} ///:~
