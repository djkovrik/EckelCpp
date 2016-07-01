/**
Create a function that returns the next value in a Fibonacci sequence every
time you call it. Add an argument that is a bool with a default value of false
such that when you give the argument with true it "resets" the function to
the beginning of the Fibonacci sequence. Exercise this function in main( ).
**/

#include <iostream>

using namespace std;

int fibonacci(bool flag = false);

int main() {

    for (int i = 0; i < 15; i++) {

        cout << fibonacci() << endl;
        if ( i == 8)
            cout << fibonacci(true) << endl;
    }

return 0;
}

int fibonacci(bool flag ) {

    static int first_num = 0;
    static int second_num = 1;

    static int current_num;

    if (flag) {
        first_num = 0;
        second_num = 1;
    }

    current_num = first_num + second_num;
    first_num = second_num;
    second_num = current_num;

    return current_num;
}
