/**
Modify PmemFunDefinition.cpp by adding an overloaded member function f( )
(you can determine the argument list that causes the overload). Now make a
second pointer to member, assign it to the overloaded version of f( ), and
call the function through that pointer. How does the overload resolution
happen in this case?
**/
class Simple2 {
public:
    int f(float) const { return 1; }
    void f(char) const {}
};

int (Simple2::*fp)(float) const;
int (Simple2::*fp2)(float) const = &Simple2::f;

void (Simple2::*fp3)(char) const = &Simple2::f;

int main() {

    fp = &Simple2::f;

    Simple2 s;
    Simple2* sPtr = &s;

    (sPtr->*fp2)(1.2);
    (sPtr->*fp3)('z');

return 0;
}
