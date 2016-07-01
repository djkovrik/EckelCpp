/**
Modify the FIELD( ) macro so that it also contains an index number.
Create a class whose members are composed of calls to the FIELD( ) macro.
Add a member function that allows you to look up a field using its index
number. Write a main( ) to test the class.
**/

#include <iostream>
#include <cstring>

using namespace std;

#define FIELD(a)    char* a##_string; int a##_size;  int a##_index
#define INIT(a,b,c) a##_string = #a;  a##_size = b;  a##_index = c

class Smth {
public:
    FIELD(one);
    FIELD(two);
    FIELD(three);

    Smth() {
        INIT(one,63,1);
        INIT(two,14,2);
        INIT(three,26,3);
    }

    void lookUp(int index);
};

void Smth::lookUp(int index) {

    const char* data = (const char*) this;

    size_t int_size = sizeof(int);
    size_t charptr_size = sizeof(char*);

    for (int i = 0; i < sizeof (*this); ++i) {

        if ( (int)(*(data + i)) == index ) {

            // MEMORY:
            // string - size - index
            //                 ^
            //               data+i
            int ind;
            int sz;
            char* str;

            memcpy (&ind, data + i, int_size );
            memcpy (&sz, data + i - int_size, int_size );
            memcpy (&str, data + i - int_size - charptr_size, charptr_size );

            cout << "\nField #" << index
                 << "\n  Index: " << ind
                 << "\n  Size: " << sz
                 << "\n  String: " << str << endl;
        }
    }
}


int main() {

    Smth s;

    s.lookUp(2);
    s.lookUp(3);
    return 0;
}
