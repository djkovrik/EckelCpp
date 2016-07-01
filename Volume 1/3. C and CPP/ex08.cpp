/**
Write a program that uses all the trigraphs to see if your compiler supports them.

Trigraphs:
??=      #
??/      \
??'      ^
??(      [
??)      ]
??!      |
??<      {
??>      }
??-      ~


Compilation command: g++ ex08.cpp -trigraphs -o ex08

**/
??=include <iostream>

using namespace std;

int main() {

    int a??( 10 ??) ;

    cout << "Hello ??/
    World!" << endl;

    if ( 1 > 2 ??!??! 2 > 3) ??<
        ??>

return 0;
}
