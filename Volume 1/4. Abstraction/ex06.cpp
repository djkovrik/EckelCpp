/**
Create a class that (redundantly) performs data member selection
and a member function call using the this keyword
(which refers to the address of the current object).
**/
#include <iostream>

using namespace std;

class MyClass {
public:
    void changeValue(int x);
    void notification();
    void printValue();
private:
    int m_value;
};

void MyClass::changeValue(int x) {
    this->notification();
    this->m_value = x;
}

void MyClass::notification() {
    cout << "Changing value..." << endl;
}

void MyClass::printValue() {
    cout << "MyClass: m_value = " << this->m_value << endl;
}


// Main

int main() {

    MyClass test;
    test.changeValue(123);
    test.printValue();

return 0;
}
