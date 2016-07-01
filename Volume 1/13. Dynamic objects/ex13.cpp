/**
Modify NoMemory.cpp so that it contains an array of int and so
that it actually allocates memory instead of throwing bad_alloc.
In main( ), set up a while loop like the one in NewHandler.cpp to
run out of memory and see what happens if your operator new does
not test to see if the memory is successfully allocated. Then add
the check to your operator new and throw bad_alloc.
**/
#include <iostream>
#include <new>

using namespace std;

class NoMemory {
public:
    NoMemory() {
        //cout << "NoMemory::NoMemory()" << endl;
    }
    void* operator new(size_t sz) throw(bad_alloc){
        //cout << "NoMemory::operator new" << endl;
        void* iPtr = new int[1000];

        if (!iPtr)
            throw bad_alloc();

    return iPtr;
    }
};

int main() {
    NoMemory* nm = nullptr;

    try {
        while(1)
            new NoMemory[1000];

    } catch(bad_alloc) {
        cerr << "Out of memory exception" << endl;
    }
    cout << "nm = " << nm << endl;

return 0;
}
