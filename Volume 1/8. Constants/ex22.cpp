/**
In ConstMember.cpp, remove the const specifier on the member function
definition, but leave it on the declaration, to see what kind of
compiler error message you get.
**/
class X {
    int i;
public:
    X(int ii);
    int f();
};

X::X(int ii) : i(ii) {}

int X::f() const {
    return i;
}

int main() {
    X x1(10);
    const X x2(20);
    x1.f();
    x2.f();
//! error: prototype for 'int X::f() const' does not match any in class 'X'|
//! error: no matching function for call to 'X::f() const'|
}
