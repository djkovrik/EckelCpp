/**
Inherit a class StringVector from vector<void*> and redefine the
push_back( ) and operator[] member functions to accept and produce
only string* (and perform the proper casting). Now create a template
that will automatically make a container class to do the same thing for
pointers to any type. This technique is often used to reduce code bloat
from too many template instantiations.
**/

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class NewVector : public vector<void*> {
public:
    void push_back(T* element) { vector<void*>::push_back(element); }
    T* operator[](size_t i) { return reinterpret_cast<T*>( vector<void*>::operator[](i) ); }
    using vector<void*>::size;
};


int main() {

    NewVector<string> nv;
    string s1("one"), s2("two"), s3("three");

    nv.push_back(&s1);
    nv.push_back(&s2);
    nv.push_back(&s3);

    for (size_t i = 0; i < nv.size(); i++)
        cout << *nv[i] << endl;

return 0;
}
