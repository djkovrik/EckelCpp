/**
Create three classes. The first class contains private data, and grants friendship
to the entire second class and to a member function of the third class. In main( ),
demonstrate that all of these work correctly.
**/
#include <iostream>

using namespace std;

class First;

class Third {
public:
    void functionFriend(First* fPtr);
    void functionNonFriend(First* fPtr);
};

class Second {
public:
    void function1(First *fPtr);
    void function2(First *fPtr);
};

class First {
friend class Second;                        // Entire class
friend void Third::functionFriend(First *); // One of functions

public:
    First() : data(123) {}
private:
    int data;
};

void Second::function1(First *fPtr) {
    cout << "Second::function1(), data = " << fPtr->data << endl;
}

void Second::function2(First *fPtr) {
    cout << "Second::function2(), data = " << fPtr->data << endl;
}

void Third::functionFriend(First* fPtr) {
    cout << "Third::functionFriend(), data = " << fPtr->data << endl;
}
void Third::functionNonFriend(First* fPtr) {
    //cout << "Third::functionNonFriend(), data = " << fPtr->data << endl;
    /// Can't access because First::data is private and this is non-friend function
}

int main() {

    First one;
    Second two;
    Third three;

    two.function1(&one);
    two.function2(&one);
    three.functionFriend(&one);
    //three.functionNonFriend(&one);

return 0;
}
