/**
Create three const int values, then add them together to produce
a value that determines the size of an array in an array definition.
Try to compile the same code in C and see what happens
(you can generally force your C++ compiler to run as a C compiler
by using a command-line flag).
**/

//!In C-mode we've got an error:
//!error: variable-sized object may not be initialized

int main() {

    const int a = 1;
    const int b = 2;
    const int c = 3;

    int array[a+b+c] = {0};

return 0;
}
