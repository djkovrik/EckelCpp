/**
Demonstrate automatic counting and aggregate initialization with
an array of objects of the class you created in Exercise 3.
Add a member function to that class that prints a message.
Calculate the size of the array and move through it,
calling your new member function.
**/
#include <iostream>

using namespace std;

class Simple {
public:
    Simple(int n) : x(n) { cout << "Simple(" << x << ") called." << endl; }
    void saySomething() { cout << "saySomething() called from Simple( " << x << ")" << endl; }
    ~Simple() { cout << "~Simple(" << x << ") called." << endl; }
private:
    int x;
};

int main() {

    Simple s[] = {Simple(1), Simple(2), Simple(3), Simple(4)};

    int array_size = sizeof(s) / sizeof(*s);

    //cout << "Array size: " << array_size << endl;

    for (int i = 0; i < array_size; i++)
        s[i].saySomething();

return 0;
}
