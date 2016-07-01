/**
Create a function that takes a char& argument and modifies that argument.
In main( ), print out a char variable, call your function for that variable,
and print it out again to prove to yourself that it has been changed.
How does this affect program readability?
**/

#include <iostream>

using namespace std;

void changeChar(char& c) {

    c = 'z';
}

int main() {

    char sym = 'a';
    cout << sym << endl;
    changeChar(sym);
    cout << sym << endl;

return 0;
}
