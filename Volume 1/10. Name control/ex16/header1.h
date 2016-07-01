#ifndef HEADER1_H_INCLUDED
#define HEADER1_H_INCLUDED

#include <iostream>

namespace MyNamespace {

    void func1() { std::cout << "func1() called." << std::endl; }
    void func2(int x) { std::cout << "func2(" << x << ") called." << std::endl; }
}


#endif // HEADER1_H_INCLUDED
