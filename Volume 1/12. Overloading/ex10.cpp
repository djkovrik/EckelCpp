/**
Determine the dummy constant value that your compiler passes for postfix operator++ and operator--.
**/

#include <iostream>

using namespace std;

class SimpleInt {
public:
    SimpleInt() : i(0) {}
    SimpleInt(int iii) : i(iii) {}

    const SimpleInt operator+(const SimpleInt& right) const { return SimpleInt(i + right.i); }

    //Postfix
    const SimpleInt operator++(int x) {
        SimpleInt s(i);
        i++;
        cout << "increment constant = " << x << endl;
        return s;
    }

     const SimpleInt operator--(int x) {
        SimpleInt s(i);
        i--;
        cout << "decrement constant = " << x << endl;
        return s;
    }
private:
    int i;
};
int main() {

    SimpleInt s;

    s++;
    s--;

return 0;
}
