/**
Create a StackOfInt class (a stack that holds ints) using the “Cheshire cat” technique
that hides the low-level data structure you use to store the elements in a class called
StackImp. Implement two versions of StackImp: one that uses a fixed-length array of int,
and one that uses a vector<int>. Have a preset maximum size for the stack so you don’t have
to worry about expanding the array in the first version. Note that the StackOfInt.h
class doesn’t have to change with StackImp.
**/
#include <iostream>
#include "StackOfInt.h"

using namespace std;

int main() {

    StackOfInt st;

    st.push_to_stack(1);
    st.push_to_stack(2);
    st.push_to_stack(3);
    st.push_to_stack(4);
    cout << "Current peek: " << st.peek_from_stack() << endl;
    st.push_to_stack(5);
    st.push_to_stack(6);
    st.print_stack();

    while ( !st.isEmpty() )
        cout << st.pop_from_stack() << endl;


return 0;
}
