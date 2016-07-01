/**
Modify the result of Exercise 1 from Chapter 15 to use the Stack
and iterator in TStack2.h instead of an array of Shape pointers.
Add destructors to the class hierarchy so you can see that the
Shape objects are destroyed when the Stack goes out of scope.

Ex 1 chapter 15:
Create a simple "shape" hierarchy: a base class called Shape and
derived classes called Circle, Square, and Triangle. In the base
class, make a virtual function called draw( ), and override this
in the derived classes. Make an array of pointers to Shape objects
that you create on the heap (and thus perform upcasting of the
pointers), and call draw( ) through the base-class pointers, to
verify the behavior of the virtual function.
If your debugger supports it, single-step through the code.
**/

#include <iostream>
#include "TStack2.h"

using namespace std;

class Shape {
public:
    Shape() { cout << "+Shape()" << endl; }
    virtual void draw() const { cout << ">Shape::draw()" << endl; }
    virtual ~Shape() { cout << "~Shape()" << endl; }
};

class Circle : public Shape {
public:
    Circle() { cout << "+Circle()" << endl; }
    void draw() const { cout << ">Circle::draw()" << endl; }
    ~Circle() { cout << "~Circle()" << endl; }
};

class Square : public Shape {
public:
    Square() { cout << "+Square()" << endl; }
    void draw() const { cout << ">Square::draw()" << endl; }
    ~Square() { cout << "~Square()" << endl; }
};

class Triangle : public Shape {
public:
    Triangle() { cout << "+Triangle()" << endl; }
    void draw() const { cout << ">Triangle::draw()" << endl; }
    ~Triangle() { cout << "~Triangle()" << endl; }
};

int main() {

    Stack<Shape> s;

    s.push(new Circle);
    s.push(new Square);
    s.push(new Triangle);

    for ( Stack<Shape>::iterator it = s.begin(); it != s.end(); it++ )
        (*it)->draw();


return 0;
}
