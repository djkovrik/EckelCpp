/**
Determine the sizeof the VPTR for your implementation. Now multiply-inherit
two classes that contain virtual functions. Did you get one VPTR or two in the derived class?
**/

#include <iostream>
#include <clocale>

using namespace std;

class Test1 {
    int x;
public:
    void f() const {}
};

class Test2 {
    int x;
public:
    virtual void f() const {}
};

class Test3 {
    int x;
public:
    virtual void g() const {}
};

class Child : public Test2, public Test3 {
    int x;
};

int main() {

    cout << "sizeof Test1 (does not have vurtual function): " << sizeof(Test1) << endl
         << "sizeof Test2 (has virtual function): " << sizeof(Test2) << endl
         << "VPTR size: " << sizeof(Test2) - sizeof(Test1) << endl
         << "sizeof(void*): " << sizeof(void*) << endl;

    cout << "sizeof Test3 (also has virtual function): " << sizeof(Test3) << endl
         << "sizeof int: " << sizeof(int) << endl
         << "sizeof multi-inherited Child: " << sizeof(Child) << endl
         << "VPTR tables: " << ( sizeof(Child) - sizeof(int) * 3 ) / sizeof(void*) << endl;

return 0;
}
