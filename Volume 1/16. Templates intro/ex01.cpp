/**
Implement the inheritance hierarchy in the OShape diagram in this chapter.
**/

#include <iostream>

using namespace std;

class Object {
public:
    virtual ~Object() {}
};

class Shape {
public:
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    ~Circle() {}
};

class Square : public Shape {
public:
    ~Square() {}
};

class Triangle : public Shape {
public:
    ~Triangle() {}
};

class OShape : public Object, public Shape {
public:
    ~OShape() {}
};

int main() {


return 0;
}
