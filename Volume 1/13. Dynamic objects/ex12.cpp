/**
Devise a test for Framis.cpp to show yourself approximately how much
faster the custom new and delete run than the global new and delete.
**/

#include <cstddef> // Size_t
#include <fstream>
#include <iostream>
#include <new>
#include <ctime>

using namespace std;

ofstream out("Framis.out");

class Framis {
    enum { sz = 10 };
    char c[sz]; // To take up space, not used
    static unsigned char pool[];
    static bool alloc_map[];
public:
    enum { psize = 100 };  // frami allowed
    Framis() { out << "Framis()\n"; }
    ~Framis() { out << "~Framis() ... "; }
    void* operator new(size_t) throw(bad_alloc);
    void operator delete(void*);
};

unsigned char Framis::pool[psize * sizeof(Framis)];
bool Framis::alloc_map[psize] = {false};

// Size is ignored -- assume a Framis object
void*
Framis::operator new(size_t) throw(bad_alloc) {
    for(int i = 0; i < psize; i++)
        if(!alloc_map[i]) {
            out << "using block " << i << " ... ";
            alloc_map[i] = true; // Mark it used
            return pool + (i * sizeof(Framis));
        }
    out << "out of memory" << endl;
    throw bad_alloc();
}

void Framis::operator delete(void* m) {
    if(!m) return; // Check for null pointer
    // Assume it was created in the pool
    // Calculate which block number it is:
    unsigned long block = (unsigned long)m
        - (unsigned long)pool;
    block /= sizeof(Framis);
    out << "freeing block " << block << endl;
    // Mark it free:
    alloc_map[block] = false;
}

int main() {

    Framis* f[Framis::psize];
    Framis* d[Framis::psize];

    cout << "Local new operator..." << endl;

    clock_t t0 = clock();

    for(int i = 0; i < Framis::psize; i++)
        f[i] = new Framis;

    cout << "Done!" << endl;

    clock_t t1 = clock();

    cout << "First (local new) time difference: " << (double)(t1 - t0) / CLOCKS_PER_SEC  << endl;

    for(int i = 0; i < Framis::psize; i++)
        delete f[i];

    cout << "Global new operator..." << endl;

    t0 = clock();

    for(int i = 0; i < Framis::psize; i++)
        d[i] = ::new Framis;

    t1 = clock();

    cout << "Second (global new) time difference: " << (double)(t1 - t0) / CLOCKS_PER_SEC  << endl;

        for(int i = 0; i < Framis::psize; i++)
        ::delete d[i];

return 0;
}
