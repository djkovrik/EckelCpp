/**
Modify Volatile.cpp from Chapter 8 to make comm::isr( ) something that could
actually work as an interrupt service routine. Hint: an interrupt service
routine doesn’t take any arguments.
**/

class Comm {
    static unsigned char byte;
    static unsigned char flag;
    enum { bufsize = 100 };
    static unsigned char buf[bufsize];
    static int index;
public:
    Comm();
    static void isr();
    char read(int index) const;
};

Comm::Comm() {}

int Comm::index = 0;
unsigned char Comm::flag = 0;
unsigned char Comm::byte = 0;
unsigned char Comm::buf[bufsize] = {0};

void Comm::isr() {
    flag = 0;
    buf[index++] = byte;
    if(index >= bufsize) index = 0;
}

char Comm::read(int index) const {
    if(index < 0 || index >= bufsize)
        return 0;
    return buf[index];
}

int main() {
    volatile Comm Port;
    Port.isr();
}
