/**
Modify the FIELD( ) macro so that it automatically generates access functions
for each field (the data should still be private, however). Create a class
whose members are composed of calls to the FIELD( ) macro.
Write a main( ) to test the class.
**/

#include <iostream>
#include <cstring>

using namespace std;

#define FIELD(a) \
private: \
    char* a##_string; int a##_size; \
public: \
    void  a##_SetStr(char* c)   { a##_string = c;} \
    void  a##_SetSize(int i)    { a##_size = i;} \
    char* a##_getStr()          { return a##_string; } \
    int   a##_getSize()         { return a##_size; }


class MyClass {
    FIELD(one);
    FIELD(two);
};


int main() {

    MyClass m;

    m.one_SetStr("field one");
    m.one_SetSize(53);

    m.two_SetStr("FIELD TWO");
    m.two_SetSize(6);

    cout << m.one_getStr() << " - " << m.one_getSize() << "\n"
         << m.two_getStr() << " - " << m.two_getSize() << endl;

return 0;
}
