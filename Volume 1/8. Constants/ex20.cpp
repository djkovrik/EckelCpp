/**
Create a class called MyString which contains a string and has a
constructor that initializes the string, and a print( ) function.
Modify StringStack.cpp so that the container holds MyString objects,
and main( ) so it prints them.
**/

#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class MyString {
public:
    MyString() : str("") {}
    MyString(string s) : str(s) {}
    void print() const { cout << "string = " << str << endl; }
private:
    string str;
};

class StringStack {
    static const int size = 100;
    const MyString* stack[size];
    int index;
public:
    StringStack();
    void push(const MyString* s);
    const MyString* pop();
};

StringStack::StringStack() : index(0) {
    memset(stack, 0, size * sizeof(MyString*));
}

void StringStack::push(const MyString* s) {
    if(index < size)
        stack[index++] = s;
}

const MyString* StringStack::pop() {
    if(index > 0) {
        const MyString* rv = stack[--index];
        stack[index] = 0;
        return rv;
    }
    return 0;
}

MyString iceCream[] = {
    MyString("pralines & cream"),
    MyString("fudge ripple"),
    MyString("jamocha almond fudge"),
    MyString("wild mountain blackberry"),
    MyString("raspberry sorbet"),
    MyString("lemon swirl"),
    MyString("rocky road"),
    MyString("deep chocolate fudge")
};

const int iCsz =
    sizeof iceCream / sizeof *iceCream;

int main() {
    StringStack ss;
    for(int i = 0; i < iCsz; i++)
        ss.push(&iceCream[i]);
    const MyString* cp;
    while((cp = ss.pop()) != 0)
        cp->print();
}
