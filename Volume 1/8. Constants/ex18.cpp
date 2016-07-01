/**
Modify ConstTemporary.cpp removing the comment on the error-causing
line to see what error messages your compiler generates.
**/

class X {};

X f() { return X(); }

void g1(X&) {}
void g2(const X&) {}

int main() {
//! error: invalid initialization of non-const reference of type 'X&' from an rvalue of type 'X'
    g1(f());

    // OK: g2 takes a const reference:
    g2(f());
}
