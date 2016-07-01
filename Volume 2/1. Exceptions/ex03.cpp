/*
Rewrite the Stash class from Chapter 13 of Volume 1 so that
it throws out_of_range exceptions for operator[ ].
*/

#include <iostream>
#include <cstring>
#include <stdexcept>

class PStash {
  int quantity; // Number of storage spaces
  int next; // Next empty space
   // Pointer storage:
  void** storage;
  void inflate(int increase);
public:
  PStash() : quantity(0), storage(0), next(0) {}
  ~PStash();
  int add(void* element);
  void* operator[](int index) const throw (std::out_of_range);
  // Remove the reference from this PStash:
  void* remove(int index);
  // Number of elements in Stash:
  int count() const { return next; }
};


int PStash::add(void* element) {
  const int inflateSize = 10;
  if(next >= quantity)
    inflate(inflateSize);
  storage[next++] = element;
  return(next - 1); // Index number
}

// No ownership:
PStash::~PStash() {
  delete []storage;
}

// Operator overloading replacement for fetch
void* PStash::operator[](int index) const throw (std::out_of_range) {
  //require(index >= 0,
  //  "PStash::operator[] index negative");
  if (index < 0)
	  throw std::out_of_range("PStash::operator[] index negative");

  if(index >= next)
    return 0; // To indicate the end
  // Produce pointer to desired element:
  return storage[index];
}

void* PStash::remove(int index) {
  void* v = operator[](index);
  // "Remove" the pointer:
  if(v != 0) storage[index] = 0;
  return v;
}

void PStash::inflate(int increase) {
  const int psz = sizeof(void*);
  void** st = new void*[quantity + increase];
  memset(st, 0, (quantity + increase) * psz);
  memcpy(st, storage, quantity * psz);
  quantity += increase;
  delete []storage; // Old storage
  storage = st; // Point to new memory
}

int main() {

 try {

	  PStash intStash;
	  // 'new' works with built-in types, too. Note
	  // the "pseudo-constructor" syntax:
	  for(int i = 0; i < 5; i++)
		 intStash.add(new int(i));

	  for(int j = 0; j < intStash.count(); j++)
		 std::cout << "intStash[" << j << "] = "
					<< *(int*)intStash[j] << std::endl;

	  auto x = intStash[-1]; //!Throws an exception
	  	  	  	  	  	  	 //!So code below becomes unreachable

	  // Clean up:
	  for(int k = 0; k < intStash.count(); k++)
		 delete intStash.remove(k);

 }
	 catch (std::out_of_range& ex) {
		 std::cout << "Exception detected: " << ex.what() << '\n';
 }

return 0;
}
