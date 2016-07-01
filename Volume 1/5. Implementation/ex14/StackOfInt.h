#ifndef STACKOFINT_H_INCLUDED
#define STACKOFINT_H_INCLUDED

#include "StackImp.h"

class StackOfInt {
public:
    StackOfInt() : intStack() {}
    void print_stack();
    void push_to_stack(int );
    int peek_from_stack();
    int pop_from_stack();
    bool isEmpty();
private:
    StackImp intStack;
};


#endif // STACKOFINT_H_INCLUDED
