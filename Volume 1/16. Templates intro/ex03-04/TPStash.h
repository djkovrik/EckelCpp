
#ifndef TPSTASH_H
#define TPSTASH_H

#include <cstring>
#include <iostream>

template<class T, int incr = 10>
class PStash {
  int quantity; // Number of storage spaces
  int next; // Next empty space
  T** storage;
  void inflate(int increase = incr);
  int callsCount;
public:
  PStash() : quantity(0), next(0), storage(0), callsCount(1) {}
  ~PStash();
  int add(T* element);
  T* operator[](int index) const; // Fetch
  // Remove the reference from this PStash:
  T* remove(int index);
  // Number of elements in Stash:
  int count() const { return next; }
};

template<class T, int incr>
int PStash<T, incr>::add(T* element) {
  if(next >= quantity)
    inflate(incr);
  storage[next++] = element;
  return(next - 1); // Index number
}

// Ownership of remaining pointers:
template<class T, int incr>
PStash<T, incr>::~PStash() {
  for(int i = 0; i < next; i++) {
    delete storage[i]; // Null pointers OK
    storage[i] = 0; // Just to be safe
  }
  delete []storage;
}

template<class T, int incr>
T* PStash<T, incr>::operator[](int index) const {

  if(index >= next)
    return 0; // To indicate the end

  // Produce pointer to desired element:
  return storage[index];
}

template<class T, int incr>
T* PStash<T, incr>::remove(int index) {
  // operator[] performs validity checks:
  T* v = operator[](index);
  // "Remove" the pointer:
  if(v != 0) storage[index] = 0;
  return v;
}

template<class T, int incr>
void PStash<T, incr>::inflate(int increase) {
  int val = increase* callsCount;
  const int psz = sizeof(T*);
  T** st = new T*[quantity + val];
  memset(st, 0, (quantity + val) * psz);
  memcpy(st, storage, quantity * psz);
  quantity += val;
  delete []storage; // Old storage
  storage = st; // Point to new memory
  std::cout << callsCount++ << ": inflate() called with " << val << std::endl;
}
#endif // TPSTASH_H ///:~
