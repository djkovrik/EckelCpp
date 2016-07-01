/**
Take the NestFriend.cpp example from Chapter 5 and replace all the
member functions with inlines. Make them non-in situ inline functions.
Also change the initialize( ) functions to constructors.
**/
#include <iostream>
#include <cstring> // memset()
using namespace std;
const int sz = 20;

struct Holder {
private:
    int a[sz];
public:
    Holder();
    struct Pointer;
    friend struct Pointer;
    struct Pointer {
    private:
        Holder* h;
        int* p;
    public:
        Pointer(Holder* h);
        // Move around in the array:
        void next();
        void previous();
        void top();
        void end();
        // Access values:
        int read();
        void set(int i);
    };
};

Holder::Holder() {
    memset(a, 0, sz * sizeof(int));
}

Holder::Pointer::Pointer(Holder* rv) {
    h = rv;
    p = rv->a;
}

inline void Holder::Pointer::next() {
    if(p < &(h->a[sz - 1])) p++;
}

inline void Holder::Pointer::previous() {
    if(p > &(h->a[0])) p--;
}

inline void Holder::Pointer::top() {
    p = &(h->a[0]);
}

inline void Holder::Pointer::end() {
    p = &(h->a[sz - 1]);
}

inline int Holder::Pointer::read() {
    return *p;
}

inline void Holder::Pointer::set(int i) {
    *p = i;
}

int main() {
    Holder h;
    int i;

    Holder::Pointer hp(&h);
    Holder::Pointer hp2(&h);
    for(i = 0; i < sz; i++) {
        hp.set(i);
        hp.next();
    }
    hp.top();
    hp2.end();
    for(i = 0; i < sz; i++) {
        cout << "hp = " << hp.read()
             << ", hp2 = " << hp2.read() << endl;
        hp.next();
        hp2.previous();
    }
} ///:~
