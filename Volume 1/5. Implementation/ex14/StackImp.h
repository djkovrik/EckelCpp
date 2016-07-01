#ifndef STACKIMP_H_INCLUDED
#define STACKIMP_H_INCLUDED

#include <vector>
using std::vector;

// const int array_size = 20;  // Variant with int[]

class StackImp {
public:
    StackImp() : data{0}, head(-1) {}
    void print();
    void push(int );
    int peek();
    int pop();
    bool empty();
private:
    // int data[array_size]; // Variant with int[]
    vector<int> data;
    int head;
};


#endif // STACKIMP_H_INCLUDED
