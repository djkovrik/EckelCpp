/**
Modify ArrayAddresses.cpp to work with the data types char, long int, float, and double.
**/

#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int a[SIZE];
    cout << "sizeof(int) = "<< sizeof(int) << endl;
    for(int i = 0; i < SIZE; i++)
        cout << "&a[" << i << "] = "
             << (long)&a[i] << endl;
/////<
    char b[SIZE];
    cout << "\nsizeof(char) = "<< sizeof(char) << endl;
    for(int i = 0; i < SIZE; i++)
        cout << "&b[" << i << "] = "
             << (long)&b[i] << endl;

    long int c[SIZE];
    cout << "\nsizeof(long int) = "<< sizeof(long int) << endl;
    for(int i = 0; i < SIZE; i++)
        cout << "&c[" << i << "] = "
             << (long)&c[i] << endl;

    float f[SIZE];
    cout << "\nsizeof(float) = "<< sizeof(float) << endl;
    for(int i = 0; i < SIZE; i++)
        cout << "&f[" << i << "] = "
             << (long)&f[i] << endl;

    double d[SIZE];
    cout << "\nsizeof(double) = "<< sizeof(double) << endl;
    for(int i = 0; i < SIZE; i++)
        cout << "&d[" << i << "] = "
             << (long)&d[i] << endl;
return 0;
}

