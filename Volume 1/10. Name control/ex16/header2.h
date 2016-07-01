#ifndef HEADER2_H_INCLUDED
#define HEADER2_H_INCLUDED

#include <iostream>
#include "header1.h"

namespace MyNamespace {

    void func3(char c) { std::cout << "func3(" << c << ") called." << std::endl; }
    void func4(int x, int y) { std::cout << "func4(" << x << "," << y << ") called." << std::endl; }
}


#endif // HEADER2_H_INCLUDED
