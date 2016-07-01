/**
Repair the problem in Exercise 32 using technique two shown in this book.
-------------
Exercise 32:

In a header file, create a class Mirror that contains two data members:
a pointer to a Mirror object and a bool. Give it two constructors:
the default constructor initializes the bool to true and the Mirror
pointer to zero. The second constructor takes as an argument a pointer
to a Mirror object, which it assigns to the object’s internal pointer;
it sets the bool to false. Add a member function test( ): if the object’s
pointer is nonzero, it returns the value of test( ) called through the
pointer. If the pointer is zero, it returns the bool. Now create five
cpp files, each of which includes the Mirror header. The first cpp file
defines a global Mirror object using the default constructor. The second
file declares the object in the first file as extern, and defines a global
Mirror object using the second constructor, with a pointer to the first
object. Keep doing this until you reach the last file, which will also
contain a global object definition. In that file, main( ) should call the
test( ) function and report the result. If the result is true, find out how
to change the linking order for your linker and change it until the result
is false.
**/

#ifndef MIRROR_H_INCLUDED
#define MIRROR_H_INCLUDED

class Mirror {
public:
    Mirror() : flag(true), mPtr(nullptr) {}
    Mirror(Mirror* m) : mPtr(m), flag(false) {}

    bool test() {
        if (mPtr)
            return mPtr->test();

        return flag;
    }

private:
    Mirror* mPtr;
    bool flag;
};

#endif // MIRROR_H_INCLUDED
