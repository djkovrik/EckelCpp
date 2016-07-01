/**
Create a program that uses an enumeration of colors. Create a variable
of this enum type and print out all the numbers that correspond with
the color names, using a for loop.
**/

#include <iostream>

using namespace std;

int main() {

    enum COLORS {RED = 1, GREEN = 3, WHITE = 5, BLUE, BLACK, YELLOW, ORANGE};

    for (COLORS next, c = RED;; c = next) {

        switch (c) {

        case RED:
            next = GREEN;
            break;
        case GREEN:
            next = WHITE;
            break;
        case WHITE:
            next = BLUE;
            break;
        case BLUE:
            next = BLACK;
            break;
        case BLACK:
            next = YELLOW;
            break;
        case YELLOW:
            next = ORANGE;
            break;
        case ORANGE:
            break;
        default:
            cout << "Error!\n";

        };

        cout << c << endl;

        if (c == ORANGE)
            break;
    }

return 0;
}
