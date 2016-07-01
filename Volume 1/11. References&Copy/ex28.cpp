/**
Modify the above Exercise 27 so that it works with pointers to member functions instead.

Ex 27:
Start with FunctionTable.cpp from Chapter 3. Create a class that contains a vector
of pointers to functions, with add( ) and remove( ) member functions to add and remove
pointers to functions. Add a run( ) function that moves through the vector and calls
all of the functions.
**/

#include <iostream>
#include <vector>

using namespace std;

class SomeFuncs {
public:
    void function1() { cout << "SomeFuncs::function1() called." << endl; }
    void function2() { cout << "SomeFuncs::function2() called." << endl; }
    void function3() { cout << "SomeFuncs::function3() called." << endl; }
};

typedef void (SomeFuncs::*function_ptr)();

class FuncStorage {
public:
    FuncStorage() : storage(), s() {}
    void add(function_ptr p) { storage.push_back(p); }
    void remove() { storage.pop_back(); }

    void run()  {

        for (int i = 0; i < storage.size(); i++)
            (&s->*storage[i])();

    }

private:
    vector<function_ptr> storage;
    SomeFuncs s;
};

int main() {

    FuncStorage obj;

    obj.add(&SomeFuncs::function1);
    obj.add(&SomeFuncs::function2);
    obj.add(&SomeFuncs::function3);

    obj.run();

    obj.remove();

    obj.run();

return 0;
}
