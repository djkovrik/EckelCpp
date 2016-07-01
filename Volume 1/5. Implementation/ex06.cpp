/**
Create a Hen class. Inside this, nest a Nest class. Inside Nest, place an Egg class.
Each class should have a display( ) member function. In main( ), create an instance
of each class and call the display( ) function for each one.
**/
#include <iostream>

using namespace std;

class Nest {
public:
    Nest() {}
    void display() {cout << "display() from Nest" << endl; }

    class Hen {
    public:
        Hen(){}
        void display() {cout << "display() from Hen" << endl; }

        class Egg {
        public:
            Egg() {}
            void display() {cout << "display() from Egg" << endl; }
        };

    };

};

int main() {

    Nest n;
    Nest::Hen h;
    Nest::Hen::Egg e;

    n.display();
    h.display();
    e.display();


return 0;
}
