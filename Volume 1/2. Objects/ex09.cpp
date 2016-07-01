/**
Create three vector<float> objects and fill the first two as in the
previous exercise. Write a for loop that adds each corresponding
element in the first two vectors and puts the result in the corresponding
element of the third vector. Display all three vectors.
**/

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int vector_size = 10;

    vector<float> vec1;
    vector<float> vec2;
    vector<float> vec3;

    // Fills vec1 and vec2
    for (int i = 0; i < vector_size; i++) {
        vec1.push_back(i + 0.2);
        vec2.push_back(i + 0.3);
    }

    // Fills vec3: vec3[i] = vec1[i] + vec2[i]
    for (int i = 0; i < vector_size; i++)
        vec3.push_back( vec1[i] + vec2[i] );

    // Prints all three vectors in vertical columns
    cout << "Vec1\tVec2\tVec3" << endl;

    for (int i = 0; i < vector_size; i++)
        cout << vec1[i] << '\t' << vec2[i] << '\t' << vec3[i] << endl;

return 0;
}
