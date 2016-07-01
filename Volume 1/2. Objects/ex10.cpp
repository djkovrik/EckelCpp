/**
Create a vector<float> and put 25 numbers into it as in the
previous exercises. Now square each number and put the result
back into the same location in the vector. Display the vector
before and after the multiplication.
**/

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int vector_size = 25;

    vector<float> vec;

    // Fills vector
    for (int i = 0; i < vector_size; i++)
        vec.push_back(i + 0.3);


    // Prints vector before square
    cout << "Before multiplication: " << endl;
    for (int i = 0; i < vector_size; i++)
        cout << vec[i] << endl;

    for (int i = 0; i < vector_size; i++)
        vec[i] = vec[i] * vec[i];

    // Prints vector after square
    cout << "\nAfter multiplication: " << endl;
    for (int i = 0; i < vector_size; i++)
        cout << vec[i] << endl;

return 0;
}
