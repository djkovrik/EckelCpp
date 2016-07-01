/**
Add a type called Tensor to OperatorPolymorphism.cpp.
**/
#include <iostream>
using namespace std;

class Matrix;
class Scalar;
class Vector;
class Tensor;

class Math {
public:
  virtual Math& operator*(Math& rv) = 0;
  virtual Math& multiply(Matrix*) = 0;
  virtual Math& multiply(Scalar*) = 0;
  virtual Math& multiply(Vector*) = 0;
  virtual Math& multiply(Tensor*) = 0;
  virtual ~Math() {}
};

class Matrix : public Math {
public:
  Math& operator*(Math& rv) {
    return rv.multiply(this); // 2nd dispatch
  }
  Math& multiply(Matrix*) {
    cout << "Matrix * Matrix" << endl;
    return *this;
  }
  Math& multiply(Scalar*) {
    cout << "Scalar * Matrix" << endl;
    return *this;
  }
  Math& multiply(Vector*) {
    cout << "Vector * Matrix" << endl;
    return *this;
  }
  Math& multiply(Tensor*) {
    cout << "Tensor * Matrix" << endl;
    return *this;
  }
};

class Scalar : public Math  {
public:
  Math& operator*(Math& rv) {
    return rv.multiply(this); // 2nd dispatch
  }
  Math& multiply(Matrix*) {
    cout << "Matrix * Scalar" << endl;
    return *this;
  }
  Math& multiply(Scalar*) {
    cout << "Scalar * Scalar" << endl;
    return *this;
  }
  Math& multiply(Vector*) {
    cout << "Vector * Scalar" << endl;
    return *this;
  }
  Math& multiply(Tensor*) {
    cout << "Tensor * Scalar" << endl;
    return *this;
  }
};

class Vector : public Math  {
public:
  Math& operator*(Math& rv) {
    return rv.multiply(this); // 2nd dispatch
  }
  Math& multiply(Matrix*) {
    cout << "Matrix * Vector" << endl;
    return *this;
  }
  Math& multiply(Scalar*) {
    cout << "Scalar * Vector" << endl;
    return *this;
  }
  Math& multiply(Vector*) {
    cout << "Vector * Vector" << endl;
    return *this;
  }
  Math& multiply(Tensor*) {
    cout << "Tensor * Vector" << endl;
    return *this;
  }
};

class Tensor : public Math  {
public:
  Math& operator*(Math& rv) {
    return rv.multiply(this); // 2nd dispatch
  }
  Math& multiply(Matrix*) {
    cout << "Matrix * Tensor" << endl;
    return *this;
  }
  Math& multiply(Scalar*) {
    cout << "Scalar * Tensor" << endl;
    return *this;
  }
  Math& multiply(Tensor*) {
    cout << "Tensor * Tensor" << endl;
    return *this;
  }
  Math& multiply(Vector*) {
    cout << "Vector * Tensor" << endl;
    return *this;
  }
};

int main() {
  Matrix m; Vector v; Scalar s; Tensor t;
  Math* math[] = { &m, &v, &s, &t };
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) {
      Math& m1 = *math[i];
      Math& m2 = *math[j];
      m1 * m2;
    }
} ///:~
