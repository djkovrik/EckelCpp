/**
Create a class with a placement new with a second argument of type string.
The class should contain a static vector<string> where the second new argument
is stored. The placement new should allocate storage as normal. In main( ),
make calls to your placement new with string arguments that describe the
calls (you may want to use the preprocessor’s __FILE__ and __LINE__ macros).
**/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

/// __LINE__ to string macro
#define S(x) #x
#define S_(x) S(x)
#define S__LINE__ S_(__LINE__)

using namespace std;

class MyClass {
public:
    MyClass() { }
    ~MyClass() { }
    void* operator new(size_t sz, string arg) {
        calls.push_back(arg);
        void* m = malloc(sz);
        return m;
    }

    static void print() {
        for(int i = 0; i < calls.size(); i++)
            cout << calls[i] << endl;
    }

private:
    static vector<string> calls;
};

vector<string> MyClass::calls;

int main() {

    MyClass* a = new(__FILE__) MyClass;
    MyClass* b = new(S__LINE__) MyClass;
    MyClass* c = new("Test argument.") MyClass;

    MyClass::print();

    delete c;
    delete b;
    delete a;

return 0;
}
