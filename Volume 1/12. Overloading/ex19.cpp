/**
Modify CopyingVsInitialization.cpp so that all of the constructors print
a message that tells you what’s going on. Now verify that the two forms
of calls to the copy-constructor (the assignment form and the parenthesized form)
are equivalent.
**/
#include <iostream>

using namespace std;

class Fi {
public:
    Fi() { cout << "Fi()" << endl; }
};

class Fee {
public:
    Fee(int) { cout << "Fee(int)" << endl; }
    Fee(const Fi&) { cout << "Fee(const Fi&)" << endl; }
};

int main() {
    Fee fee = 1;
    Fi fi;
    Fee fum = fi;
    Fee fim(fi);
}
