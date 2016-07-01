/**
Create a program that asks for the radius of a circle and prints the area of that circle.
You can just use the ‘*’ operator to square the radius.
Do not try to print out the value as octal or hex
(these only work with integral types).
**/

#include <iostream>

using namespace std;

int main() {

    const double pi = 3.14;

    int radius;

    cout << "Please enter the cicrle radius: ";
    cin >> radius;

    double area;
    area = pi * radius * radius;

    cout << "Circle area: " << area << endl;


return 0;
}
