#include <iostream>
using std::cout;
using std::endl;

#include "StackImp.h"

void StackImp::print() {
   for (int i = head; i >= 0; i--)
        cout << data[i] << ' ';

    cout << endl;
}

void StackImp::push(int x) {
    // Variant with int[]
    //if (head >= array_size) {
    //    cout << "Stack is full!" << endl;
    //    return;
    //}
    cout << "Push(" << x << ")" << endl;
    data[++head] = x;
}

int StackImp::peek() {
    return (head >= 0) ? data[head] : 0;
}

int StackImp::pop() {
    if (head == -1)
        return 0;

    cout << "Pop(" << data[head] << ")" << endl;
    int element = data[head];
    data[head--] = 0;
    return element;
}

bool StackImp::empty() {
    return (head == -1);
}
