/**
Repeat Exercise 7 with Stack:
Make a Stach (Stack) that holds doubles. Fill it with 25 double values,
then print them out to the console.
**/

#include <fstream>
#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int main() {

    Stack doubleStack;
    doubleStack.initialize();

    double modifier = 0.1;
    const int stack_size = 25;

    for (int i = 0; i < stack_size; i++)
        doubleStack.push(new double (i * modifier + modifier));

    double *dPtr;

    while ( (dPtr = (double*) doubleStack.pop()) != nullptr ) {

        cout << *dPtr << endl;
        delete dPtr;
    }

return 0;
}
