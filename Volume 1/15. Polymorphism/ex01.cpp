/**
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

using namespace std;

class Shape {
public:
    virtual void draw() const { cout << "Shape::draw()" << endl; }
    virtual ~Shape() { cout << "~Shape()" << endl; }
};

class Circle : public Shape {
public:
    void draw() const { cout << "Circle::draw()" << endl; }
    ~Circle() { cout << "~Circle()" << endl; }
};

class Square : public Shape {
public:
    void draw() const { cout << "Square::draw()" << endl; }
    ~Square() { cout << "~Square()" << endl; }
};

class Triangle : public Shape {
public:
    void draw() const { cout << "Triangle::draw()" << endl; }
    ~Triangle() { cout << "~Triangle()" << endl; }
};

int main() {

    Shape* s[] = {new Circle, new Square, new Triangle};

    for (size_t i = 0; i < sizeof(s) / sizeof(*s); i++)
        s[i]->draw();

    for (size_t i = 0; i < sizeof(s) / sizeof(*s); i++) {
        delete s[i];
        s[i] = 0;
    }

return 0;
}
