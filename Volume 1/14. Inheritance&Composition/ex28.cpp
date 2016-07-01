/**
Modify ArrayOperatorNew.cpp from Chapter 13 to show that, if you
inherit from Widget, the allocation still works correctly. Explain
why inheritance in Framis.cpp from Chapter 13 would not work correctly.
**/
#include <new> // Size_t definition
#include <fstream>
using namespace std;
ofstream trace("ex28.out");

class Widget {
  enum { sz = 10 };
  int i[sz];
public:
  Widget() { trace << "*"; }
  ~Widget() { trace << "~"; }
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
};

class Child : public Widget {};

int main() {
  trace << "new Child" << endl;
  Child* w = new Child;
  trace << "\ndelete Child" << endl;
  delete w;
  trace << "\nnew Child[25]" << endl;
  Child* wa = new Child[25];
  trace << "\ndelete []Child" << endl;
  delete []wa;
} ///:~
