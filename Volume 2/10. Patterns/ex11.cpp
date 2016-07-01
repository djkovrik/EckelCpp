/*
Add a class Triangle to ShapeFactory2.cpp.
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstddef>
#include "purge.h"

using namespace std;

class Shape {
public:
	virtual void draw() = 0;
	virtual void erase() = 0;
	virtual ~Shape() {}
};

class ShapeFactory {
	virtual Shape* create() = 0;
	static map<string, ShapeFactory*> factories;
public:
	virtual ~ShapeFactory() {}
	friend class ShapeFactoryInitializer;
	class BadShapeCreation : public logic_error {
	public:
		BadShapeCreation(string type)
		: logic_error("Cannot create type " + type) {}
	};
	static Shape*
	createShape(const string& id) throw(BadShapeCreation) {
		if(factories.find(id) != factories.end())
			return factories[id]->create();
		else
			throw BadShapeCreation(id);
	}
};

// Define the static object:
map<string, ShapeFactory*> ShapeFactory::factories;

class Circle : public Shape {
	Circle() {} // Private constructor
	friend class ShapeFactoryInitializer;
	class Factory;
	friend class Factory;
	class Factory : public ShapeFactory {
	public:
		Shape* create() { return new Circle; }
		friend class ShapeFactoryInitializer;
	};
public:
	void draw() { cout << "Circle::draw" << endl; }
	void erase() { cout << "Circle::erase" << endl; }
	~Circle() { cout << "Circle::~Circle" << endl; }
};

class Square : public Shape {
	Square() {}
	friend class ShapeFactoryInitializer;
	class Factory;
	friend class Factory;
	class Factory : public ShapeFactory {
	public:
		Shape* create() { return new Square; }
		friend class ShapeFactoryInitializer;
	};
public:
	void draw() { cout << "Square::draw" << endl; }
	void erase() { cout << "Square::erase" << endl; }
	~Square() { cout << "Square::~Square" << endl; }
};

class Triangle : public Shape {
	Triangle() {}
	friend class ShapeFactoryInitializer;
	class Factory;
	friend class Factory;
	class Factory : public ShapeFactory {
	public:
		Shape* create() { return new Triangle; }
		friend class ShapeFactoryInitializer;
	};
public:
	void draw() { cout << "Triangle::draw" << endl; }
	void erase() { cout << "Triangle::erase" << endl; }
	~Triangle() { cout << "Triangle::~Square" << endl; }
};

// Singleton to initialize the ShapeFactory:
class ShapeFactoryInitializer {
	static ShapeFactoryInitializer si;
	ShapeFactoryInitializer() {
		ShapeFactory::factories["Circle"]= new Circle::Factory;
		ShapeFactory::factories["Square"]= new Square::Factory;
		ShapeFactory::factories["Triangle"]= new Triangle::Factory;
	}
	~ShapeFactoryInitializer() {
		map<string, ShapeFactory*>::iterator it =
			ShapeFactory::factories.begin();
		while(it != ShapeFactory::factories.end())
			delete it++->second;
	}
};

// Static member definition:
ShapeFactoryInitializer ShapeFactoryInitializer::si;

char* sl[] = { "Circle", "Square", "Square",
	"Circle", "Triangle", "Circle", "Triangle" };

int main() {
	vector<Shape*> shapes;
	try {
		for(size_t i = 0; i < sizeof sl / sizeof sl[0]; i++)
			shapes.push_back(ShapeFactory::createShape(sl[i]));
	} catch(ShapeFactory::BadShapeCreation& e) {
		cout << e.what() << endl;
		return EXIT_FAILURE;
	}
	for(size_t i = 0; i < shapes.size(); i++) {
		shapes[i]->draw();
		shapes[i]->erase();
	}
	purge(shapes);
}
