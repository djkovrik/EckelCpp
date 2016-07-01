/**
Create a class with an overloaded operator new and delete, both the single-object
versions and the array versions. Demonstrate that both versions work.
**/

#include <iostream>
#include <cstdlib>
#include <new>

using namespace std;

class MyClass {
public:
    MyClass() : x(++count) { cout << "++ MyClass(" << x << ") constructor." << endl; }
    ~MyClass() { cout << "-- MyClass(" << x << ") destructor." << endl; --count; }

    void* operator new(size_t s) {
        cout << "MyClass::operator new called." << endl;
        void* ptr = malloc(s);
        return ptr;
    }

    void operator delete(void* s) {
        cout << "MyClass::operator delete called." << endl;

    }

    void* operator new[](size_t s) {
        cout << "MyClass::operator new[] called." << endl;
        return ::new int[s];

    }

    void operator delete[](void* s) {
        cout << "MyClass::operator []delete called." << endl;
        ::delete []s;
    }

private:
    int x;
    static int count;
};

int MyClass::count = 0;

int main() {

    MyClass* aPtr = new MyClass;
    MyClass* bPtr = new MyClass[5];

    delete aPtr;
    delete []bPtr;

return 0;
}
