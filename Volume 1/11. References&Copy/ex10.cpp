/**
Write a simple function that takes an int as an argument, increments the value,
and returns it. In main( ), call your function. Now discover how your compiler
generates assembly code and trace through the assembly statements so that you
understand how arguments are passed and returned, and how local variables are
indexed off the stack.
**/

/// Compilation command:
/// g++ -S -masm=intel -g ex10.cpp -o ex10.s

using namespace std;

int increment(int x) {
    x++;
    return x;
}

int main() {

    int y = 10;
    increment(y);

return 0;
}
