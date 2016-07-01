/*
Change StlShape.cpp so that it uses a deque instead of a vector.
*/

//: C07:Stlshape.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Simple shapes using the STL.

//-#include <vector>
#include <deque> //+
#include <iostream>
using namespace std;

class Shape {
public:
  virtual void draw() = 0;
  virtual ~Shape() {};
};

class Circle : public Shape {
public:
  void draw() { cout << "Circle::draw" << endl; }
  ~Circle() { cout << "~Circle" << endl; }
};

class Triangle : public Shape {
public:
  void draw() { cout << "Triangle::draw" << endl; }
  ~Triangle() { cout << "~Triangle" << endl; }
};

class Square : public Shape {
public:
  void draw() { cout << "Square::draw" << endl; }
  ~Square() { cout << "~Square" << endl; }
};

int main() {
  //=typedef std::vector<Shape*> Container;
  typedef std::deque<Shape*> Container;//+
  typedef Container::iterator Iter;
  Container shapes;
  shapes.push_back(new Circle);
  shapes.push_back(new Square);
  shapes.push_back(new Triangle);
  for(Iter i = shapes.begin(); i != shapes.end(); i++)
    (*i)->draw();
  // ... Sometime later:
  for(Iter j = shapes.begin(); j != shapes.end(); j++)
    delete *j;
} ///:~
