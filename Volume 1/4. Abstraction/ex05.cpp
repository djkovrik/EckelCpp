/**
Repeat Exercise 4 but move the functions so they are member functions of the struct, and test again.
**/
#include <iostream>

using namespace std;

struct MyStruct {
    int s_value;

    void changeValue(int x);
    void printValue();
};

void MyStruct::changeValue(int x) {
    s_value = x;
}

void MyStruct::printValue() {
    cout << "MyStruct: s_value = " << s_value << endl;
}

// Main

int main() {

    MyStruct s;
    s.changeValue(123);
    s.printValue();

return 0;
}
