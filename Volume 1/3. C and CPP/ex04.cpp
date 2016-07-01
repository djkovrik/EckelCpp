/**
Modify Menu.cpp to use switch statements instead of if statements.
**/

#include <iostream>

using namespace std;

int main() {
    char c; // To hold response
    bool flag = true;

    while(flag) {
        cout << "MAIN MENU:" << endl;
        cout << "l: left, r: right, q: quit -> ";
        cin >> c;
    switch (c) {

    case 'q':
        flag = false;
        break; // Out of "while(1)"

    case 'l':
        cout << "LEFT MENU:" << endl;
        cout << "select a or b: ";
        cin >> c;
            switch (c) {
            case 'a':
                cout << "you chose 'a'" << endl;
                continue;

            case 'b':
                cout << "you chose 'b'" << endl;
                continue; // Back to main menu

            default:
                cout << "you didn't choose a or b!" << endl;
                continue;
              }

    case 'r':
        cout << "RIGHT MENU:" << endl;
        cout << "select c or d: ";
        cin >> c;
        switch(c) {
        case 'c':
            cout << "you chose 'c'" << endl;
            continue; // Back to main menu

        case 'd':
            cout << "you chose 'd'" << endl;
            continue; // Back to main menu

        default:
            cout << "you didn't choose c or d!" << endl;
            continue; // Back to main menu
          }

    default:
        cout << "you must type l or r or q!" << endl;

        }
    } // while

    cout << "quitting menu..." << endl;

return 0;
}
