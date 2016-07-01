/**
Create a header file with an unnamed namespace. Include the header in two
separate cpp files and show that an unnamed space is unique for each
translation unit.
**/

#include <iostream>

using namespace std;

extern void setX1(int );
extern void setX2(int );
extern int getX1();
extern int getX2();

int main() {

    setX1(11);
    setX2(22);

    cout << "x in first file: " << getX1() << endl;
    cout << "x in second file: " << getX2() << endl;

return 0;
}
