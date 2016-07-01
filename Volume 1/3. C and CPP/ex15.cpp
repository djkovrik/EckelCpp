/**
Create a struct that holds two string objects and one int. Use a typedef
for the struct name. Create an instance of the struct, initialize all
three values in your instance, and print them out. Take the address of
your instance and assign it to a pointer to your struct type. Change the
three values in your instance and print them out, all using the pointer.
**/

#include <iostream>
#include <string>

using namespace std;

typedef struct Structure1 {
        string fieldOne;
        string fieldTwo;
        int number;
    } Structure1;

int main() {

    Structure1 st;

    st.fieldOne = "field one";
    st.fieldTwo = "field two";
    st.number = 666;

    Structure1 *stPointer = &st;

    cout << "Initial structure:\n"
         << "fieldOne = " << st.fieldOne
         << "\nfieldTwo = " << st.fieldTwo
         << "\nnumber = " << st.number
         << "\nAdress: " << stPointer << endl;

    stPointer->fieldOne = "modified field one";
    stPointer->fieldTwo = "modified field two";
    stPointer->number = 456;

    cout << "\n------------\n"
         << "Modified structure:\n"
         << "fieldOne = " << stPointer->fieldOne
         << "\nfieldTwo = " << stPointer->fieldTwo
         << "\nnumber = " << stPointer->number
         << "\n------------"
         << "\nAdress: " << stPointer << endl;

return 0;
}
