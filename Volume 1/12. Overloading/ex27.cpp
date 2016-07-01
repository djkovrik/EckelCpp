/**
Add an operator-- to SmartPointer.cpp and NestedSmartPointer.cpp.
**/
#include <iostream>
#include <vector>

using namespace std;

class Obj {
  static int i, j;
public:
  void f() { cout << i++ << endl; }
  void g() { cout << j++ << endl; }

  typedef void (Obj::*PMF)(void);

  class FunctionObject {
    Obj* ptr;
    PMF pmem;
  public:
    // Save the object pointer and member pointer
    FunctionObject(Obj* wp, PMF pmf)
      : ptr(wp), pmem(pmf) {
      cout << "FunctionObject constructor\n";
    }
    // Make the call using the object pointer
    // and member pointer
    void operator()(void) const {
      cout << "FunctionObject::operator()\n";
      (ptr->*pmem)(); // Make the call
    }
  };

  FunctionObject operator->*(PMF pmf) {
    cout << "operator->*" << endl;
    return FunctionObject(this, pmf);
  }

};

// Static member definitions:
int Obj::i = 47;
int Obj::j = 11;

// Container:
class ObjContainer {
  vector<Obj*> a;
public:
  void add(Obj* obj) { a.push_back(obj); }
  class SmartPointer;
  friend class SmartPointer;
  class SmartPointer {
    ObjContainer& oc;
    unsigned int index;
  public:
    SmartPointer(ObjContainer& objc) : oc(objc) {
      index = 0;
    }
    // Return value indicates end of list:
    bool operator++() { // Prefix
      if(index >= oc.a.size()) return false;
      if(oc.a[++index] == 0) return false;
      return true;
    }
    bool operator++(int) { // Postfix
      return operator++(); // Use prefix version
    }
    Obj* operator->() const {
      return oc.a[index];
    }
  };
  // Function to produce a smart pointer that
  // points to the beginning of the ObjContainer:
  SmartPointer begin() {
    return SmartPointer(*this);
  }
};

int main() {
  const int sz = 10;
  Obj o[sz];
  ObjContainer oc;
  for(int i = 0; i < sz; i++)
    oc.add(&o[i]); // Fill it up
  ObjContainer::SmartPointer sp = oc.begin();
  do {
     Obj::PMF pmf1 = &Obj::f;
     Obj::PMF pmf2 = &Obj::g;

     // Getting current Obj* and applying PMF to it
    ( sp.operator->()->*pmf1 )();
    ( sp.operator->()->*pmf2 )();

  } while(++sp);
} ///:~
