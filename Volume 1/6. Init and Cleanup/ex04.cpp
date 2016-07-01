/**
Demonstrate that destructors are still called even when goto is used to jump out of a loop.
**/
#include <iostream>

using namespace std;

class Simple {
public:
    Simple(int n) : x(n) { cout << "Simple(" << x << ") called." << endl; }
    ~Simple() { cout << "~Simple(" << x << ") called." << endl; }
private:
    int x;
};


int main() {

    for (int i = 0; i < 4; i++) {
        Simple s(i);

        if (i == 2)
            goto end;
    }

end:

return 0;
}
