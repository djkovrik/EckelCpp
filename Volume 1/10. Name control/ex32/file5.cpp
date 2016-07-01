#include "Mirror.h"
#include <iostream>

extern Mirror m4;
Mirror m5(&m4);

bool result = m5.test();

int main() {

    std::cout.setf(std::ios::boolalpha);
    std::cout << result << std::endl;

return 0;
}
