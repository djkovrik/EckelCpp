/**
Create an array of string objects and assign a string to each element. Print out the array using a for loop.
**/
#include <iostream>
#include <string>

using namespace std;

int main() {

    const int SIZE = 3;

    string s[SIZE];

    s[0] = "line one";
    s[1] = "line two";
    s[2] = "line three";

    for (int i = 0; i < SIZE; i++)
        cout << s[i] << endl;

return 0;
}
