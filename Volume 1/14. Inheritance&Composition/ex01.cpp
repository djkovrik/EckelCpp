/**
Modify Car.cpp so that it also inherits from a class called Vehicle,
placing appropriate member functions in Vehicle (that is, make up some
member functions). Add a nondefault constructor to Vehicle, which you
must call inside Car’s constructor.
**/

#include <iostream>

using namespace std;

class Vehicle {
public:
    Vehicle(int x) : index(x) { cout << "Vehicle(" << index << ")" << endl; }
    void beep() const { cout << "Beep, beep!" << endl; }
private:
    int index;
};

class Engine {
public:
    void start() const {}
    void rev() const {}
    void stop() const {}
};

class Wheel {
public:
  void inflate(int psi) const {}
};

class Window {
public:
    void rollup() const {}
    void rolldown() const {}
};

class Door {
public:
    Window window;
    void open() const {}
    void close() const {}
};

class Car : public Vehicle {
public:
    Car() : Vehicle(0) { cout << "Car()" << endl; }
    Engine engine;
    Wheel wheel[4];
    Door left, right;
};

int main() {
    Car car;
    car.left.window.rollup();
    car.wheel[0].inflate(72);
    car.beep();
}
