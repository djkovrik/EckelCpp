/**
Write a program that prints out all the sizes for the fundamental data types on your computer using sizeof.
**/

#include <iostream>

using namespace std;

int main() {

    cout << "sizeof(char): " << sizeof(char)
         << "\nsizeof(unsigned char): " << sizeof(unsigned char)
         << "\nsizeof(int): " << sizeof(int)
         << "\nsizeof(unsigned int): " << sizeof(unsigned int)
         << "\nsizeof(short int): " << sizeof(short int)
         << "\nsizeof(unsigned short int): " << sizeof(unsigned short int)
         << "\nsizeof(long int): " << sizeof(long int)
         << "\nsizeof(unsigned long int): " << sizeof(unsigned long int)
         << "\nsizeof(float): " << sizeof(float)
         << "\nsizeof(double): " << sizeof(double)
         << "\nsizeof(long double): " << sizeof(long double)
         << "\nsizeof(bool): " << sizeof(bool) << endl;


return 0;
}
