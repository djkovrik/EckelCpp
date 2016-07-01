/**
Find out how to produce assembly language from your C and C++
compilers. Write a struct with a single member function in C++.
Produce assembly language from each and find the function names
that are produced by your C++ member function, so you can see
what sort of name decoration occurs inside the compiler.
**/

// Compilation params: g++ -S -masm=intel -g ex10.cpp -o ex10.s

#include <iostream>

using namespace std;

struct MyStruct {
    void someFunc(int x) {}
};

int main() {

    MyStruct m;

return 0;
}
