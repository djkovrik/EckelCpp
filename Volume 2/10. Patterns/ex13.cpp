/*
Modify ShapeFactory2.cpp so that it uses an Abstract Factory
to create different sets of shapes (for example, one particular
type of factory object creates “thick shapes,” another creates
“thin shapes,” but each factory object can create all the shapes:
circles, squares, triangles, and so on).
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

class ThinCircle : public Shape {
public:
  ThinCircle() {}
  void draw() { cout << "ThinCircle::draw" << endl; }
  void erase() { cout << "ThinCircle::erase" << endl; }
  ~ThinCircle() { cout << "ThinCircle::~Circle" << endl; }
};

class ThinSquare : public Shape {
public:
  ThinSquare() {}
  void draw() { cout << "ThinSquare::draw" << endl; }
  void erase() { cout << "ThinSquare::erase" << endl; }
  ~ThinSquare() { cout << "ThinSquare::~Square" << endl; }
};

class ThickCircle : public Shape {
public:
  ThickCircle() {}
  void draw() { cout << "ThickCircle::draw" << endl; }
  void erase() { cout << "ThickCircle::erase" << endl; }
  ~ThickCircle() { cout << "ThickCircle::~Circle" << endl; }
};

class ThickSquare : public Shape {
public:
  ThickSquare() {}
  void draw() { cout << "ThickSquare::draw" << endl; }
  void erase() { cout << "ThickSquare::erase" << endl; }
  ~ThickSquare() { cout << "ThickSquare::~Square" << endl; }
};

// The abstract factory:
class ShapeAbstractFactory {
public:
  virtual Shape* makeCircle() = 0;
  virtual Shape* makeSquare() = 0;
  virtual ~ShapeAbstractFactory() {}
};

class ThinFactory : public ShapeAbstractFactory {
public:
  virtual Shape* makeCircle() { return new ThinCircle(); }
  virtual Shape* makeSquare() { return new ThinSquare(); }
};

class ThickFactory : public ShapeAbstractFactory {
public:
  virtual Shape* makeCircle() { return new ThickCircle(); }
  virtual Shape* makeSquare() { return new ThickSquare(); }
};

class ShapeEnvironment {
	ShapeAbstractFactory* saf;
	Shape* circle;
	Shape* square;
public:
	ShapeEnvironment(ShapeAbstractFactory* factory)
  : saf(factory),
	circle(factory->makeCircle()),
	square(factory->makeSquare()) {}

  void draw_all() {
	  circle->draw();
	  circle->erase();
	  square->draw();
	  square->erase();
  }

  ~ShapeEnvironment() {
    delete saf;
    delete circle;
    delete square;
  }
};

int main() {

	ShapeEnvironment s1(new ThinFactory), s2(new ThickFactory);

	s1.draw_all();
	s2.draw_all();

}
