/**
Modify ArrayOperatorNew.cpp by adding a static vector<Widget*> that
adds each Widget address that is allocated in operator new( ) and
removes it when it is released via operator delete( ). (You may need
to look up information about vector in your Standard C++ Library
documentation or in the 2nd volume of this book, available at
the Web site.) Create a second class called MemoryChecker that has
a destructor that prints out the number of Widget pointers in your
vector. Create a program with a single global instance of MemoryChecker
and in main( ), dynamically allocate and destroy several objects and
arrays of Widget. Show that MemoryChecker reveals memory leaks.
**/

#include <new>
#include <fstream>
#include <vector>

using namespace std;
ofstream trace("ex15.out");

class Widget {
    enum { sz = 10 };
    int i[sz];
    static vector<Widget*> pointers;
public:
    Widget()  { trace << "*"; pointers.push_back(this); }
    ~Widget() { trace << "~"; pointers.pop_back();      }
    void* operator new(size_t sz) {
        trace << "Widget::new: "
                 << sz << " bytes" << endl;
        return ::new char[sz];
    }
    void operator delete(void* p) {
        trace << "Widget::delete" << endl;
        ::delete []p;
    }
    void* operator new[](size_t sz) {
        trace << "Widget::new[]: "
                 << sz << " bytes" << endl;
        return ::new char[sz];
    }
    void operator delete[](void* p) {
        trace << "Widget::delete[]" << endl;
        ::delete []p;
    }

    static void check() {
        trace << ">>>> Pointers in vector: " << pointers.size() << endl;

        for (size_t i = 0; i < pointers.size(); i++)
            trace << '\t' << pointers[i] << endl;
    }
};

vector<Widget*> Widget::pointers;

class MemoryChecker {
public:
    ~MemoryChecker() { Widget::check(); }
};

MemoryChecker m;

int main() {
    trace << "new Widget" << endl;
    Widget* w = new Widget;
    trace << "\ndelete Widget" << endl;
    delete w;
    trace << "\nnew Widget[25]" << endl;
    Widget* wa = new Widget[25];
    trace << "\ndelete []Widget" << endl;
    delete []wa;
}

/*
new Widget
Widget::new: 40 bytes
*
delete Widget
~Widget::delete

new Widget[25]
Widget::new[]: 1004 bytes
*************************
delete []Widget
~~~~~~~~~~~~~~~~~~~~~~~~~Widget::delete[]
>>>> Pointers in vector: 0
*/
