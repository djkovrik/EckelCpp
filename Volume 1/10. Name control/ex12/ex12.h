#ifndef EX12_H_INCLUDED
#define EX12_H_INCLUDED

#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass(int value) : x(value) {}
    void print() { cout << "x = " << x << endl; }
private:
    int x;
};

#endif // EX12_H_INCLUDED
