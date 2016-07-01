/**
Create a class that contains a double*. The constructor initializes the double*
by calling new double and assigning a value to the resulting storage from the
constructor argument. The destructor prints the value that’s pointed to, assigns
that value to -1, calls delete for the storage, and then sets the pointer to zero.
Now create a function that takes an object of your class by value, and call this
function in main( ). What happens? Fix the problem by writing a copy-constructor.
**/

#include <iostream>

using namespace std;

class MyDouble {
public:
    MyDouble() : dptr(nullptr) {}
    MyDouble(double d) : dptr(new double (d)) {}

    MyDouble(const MyDouble& x) : dptr(x.dptr) {}

    ~MyDouble() {
        cout << "~MyDouble():" << *dptr << endl;
        //*dptr = -1;
        delete dptr;
        dptr = nullptr;
    }
private:
    double* dptr;
};

void someFunc(MyDouble x) {
    cout << "someFunc() called."<< endl;
}

int main() {

    MyDouble obj(1.2);
    someFunc(obj);

return 0;
}
