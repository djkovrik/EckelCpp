/**
Modify Exercise 6 so that Nest and Egg each contain private data.
Grant friendship to allow the enclosing classes access to this private data.

Ex 6:
Create a Hen class. Inside this, nest a Nest class. Inside Nest, place an Egg class.
Each class should have a display( ) member function. In main( ), create an instance
of each class and call the display( ) function for each one.
**/
#include <iostream>

using namespace std;

class Nest {
public:
    Nest() {}
    void display() {cout << "display() from Nest" << endl; h.display(); }

// Hen
    class Hen {
    friend Nest;
    public:
        Hen(){}
    private:
        void display() { cout << "display() from Hen" << endl; e.display(); }
    // Egg
        class Egg {
        friend Hen;
        public:
            Egg() {}
        private:
            void display() {cout << "display() from Egg" << endl; }
        } e;
    // Egg
    } h;
// Hen
};

int main() {

    Nest n;
    n.display();

return 0;
}
