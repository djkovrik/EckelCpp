/**
Start with FunctionTable.cpp from Chapter 3. Create a class that contains a vector
of pointers to functions, with add( ) and remove( ) member functions to add and remove
pointers to functions. Add a run( ) function that moves through the vector and calls
all of the functions.
**/

#include <iostream>
#include <vector>

using namespace std;

// A macro to define dummy functions:
#define DF(N) void N() { \
   cout << "function " #N " called..." << endl; }

DF(a); DF(b); DF(c);

typedef void (*function_ptr)();

class FuncStorage {
public:
    FuncStorage() : storage() {}
    void add(function_ptr p) { storage.push_back(p); }
    void remove() { storage.pop_back(); }

    void run()  {
        for (int i = 0; i < storage.size(); i++)
            storage[i]();
    }
private:
    vector<function_ptr> storage;
};

int main() {

    FuncStorage obj;

    obj.add(a);
    obj.add(b);
    obj.add(c);

    obj.run();

    obj.remove();

    obj.run();

return 0;
}
