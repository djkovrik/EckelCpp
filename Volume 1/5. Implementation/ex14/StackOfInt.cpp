#include "StackOfInt.h"

void StackOfInt::print_stack() {
    intStack.print();
}

void StackOfInt::push_to_stack(int x) {
    intStack.push(x);
}

int StackOfInt::peek_from_stack() {
    return intStack.peek();
}

int StackOfInt::pop_from_stack() {
    return intStack.pop();
}

bool StackOfInt::isEmpty() {
    return intStack.empty();
}
