/**
Create a struct declaration with a single member function, then create a
definition for that member function. Create an object of your new data type,
and call the member function.
**/

#include <iostream>

using namespace std;

struct MyStruct {
    void someFunc();
};

void MyStruct::someFunc() {

    cout << "someFunc() called..." << endl;

}

int main() {

    MyStruct m;
    m.someFunc();

return 0;
}
