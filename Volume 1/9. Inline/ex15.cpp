/**
Create a large quantity of the objects from the previous Exercise,
and use the Time class to time the difference between non-inline constructors
and inline constructors. (If you have a profiler, also try using that.)
**/

#include "Cpptime.h"
#include <iostream>

using namespace std;

class A_inline {
public:
    A_inline() { cout << "A_inline()" << endl; }
};

class B_inline {
public:
    B_inline() : a_i() { cout << "B_inline()" << endl; }
private:
    A_inline a_i;
};

class A {
public:
    A();
};

A::A() { cout << "A()" << endl; }

class B {
public:
    B();
private:
    A a;
};

B::B() : a() { cout << "B()" << endl; }

int main() {

    Time start_inline;
    B_inline b_i[10000];
    Time end_inline;

    Time start;
    B b[10000];
    Time end;


    cout << "Inline constructors: \n"
         << "start = " << start_inline.ascii()
         << "end = " << end_inline.ascii()
         << "delta = " << end_inline.delta(&start_inline)

         << "\nNon-Inline constructors: \n"
         << "start = " << start.ascii()
         << "end = " << end.ascii()
         << "delta = " << end.delta(&start);


return 0;
}
