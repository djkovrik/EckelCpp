/**
Determine how to generate assembly output with your compiler,
and run experiments to deduce the name-decoration scheme.
**/
/*
Compile with: g++ -S -masm=intel -g ex03.cpp -o ex03.s

Name-decoration scheme:
    __ZN9SomeClassC2Ev
    __ZN9SomeClass8someFuncEi
    __ZN9SomeClass8someFuncEc

*/

#include <iostream>

using namespace std;

class SomeClass {
public:
    SomeClass();
    void someFunc(int x);
    void someFunc(char y);
private:
    int someData;
};

SomeClass::SomeClass() : someData(1) {}

void SomeClass::someFunc(int x) { cout << x << '\n' << someData << endl; }

void SomeClass::someFunc(char y) { cout << y << '\n' << someData << endl; }

int main() {

    SomeClass s;
    s.someFunc(1);
    s.someFunc('2');

return 0;
}
