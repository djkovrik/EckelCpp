/**
Write a program that uses a while loop to read words from
standard input (cin) into a string. This is an "infinite" while loop,
which you break out of (and exit the program) using a break statement.
For each word that is read, evaluate it by first using a sequence of if
statements to "map" an integral value to the word, and then use a switch
statement that uses that integral value as its selector (this sequence of
events is not meant to be good programming style; it’s just supposed to
give you exercise with control flow). Inside each case, print something
meaningful. You must decide what the "interesting" words are and what the
meaning is. You must also decide what word will signal the end of the program.
**/

#include <iostream>
#include <string>

using namespace std;

int main() {

    string buf;
    int choise = 10;

    do {
        cout << "Please enter digit name from 1 to 9 (0 for exit): ";
        cin >> buf;

        if (buf == "one")
            choise = 1;
        else if (buf == "two")
            choise = 2;
        else if (buf == "three")
            choise = 3;
        else if (buf == "four")
            choise = 4;
        else if (buf == "five")
            choise = 5;
        else if (buf == "six")
            choise = 6;
        else if (buf == "seven")
            choise = 7;
        else if (buf == "eight")
            choise = 8;
        else if (buf == "nine")
            choise = 9;
        else if (buf == "zero")
            choise = 0;
        else
            choise = -1;

        if (choise == 0)
            break;

        switch (choise) {

            case 1:
                cout << "Entered num: 1!\n";
                break;
            case 2:
                cout << "Entered num: 2!\n";
                break;
            case 3:
                cout << "Entered num: 3!\n";
                break;
            case 4:
                cout << "Entered num: 4!\n";
                break;
            case 5:
                cout << "Entered num: 5!\n";
                break;
            case 6:
                cout << "Entered num: 6!\n";
                break;
            case 7:
                cout << "Entered num: 7!\n";
                break;
            case 8:
                cout << "Entered num: 8!\n";
                break;
            case 9:
                cout << "Entered num: 9!\n";
                break;
            case 0:
                cout << "Entered num: 0!\n";
                break;
            default:
                cout << "Wrong number!\n";
                break;
        };

    }   while (true);

return 0;
}
