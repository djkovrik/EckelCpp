#ifndef MEM2_H
#define MEM2_H
typedef unsigned char byte;

class Mem {
    byte* memory;       // Storage
    int memory_size;    // Storage size
public:
    Mem(int sz = 0);
    ~Mem();
    int msize();
    void ensureMinSize(int minSize);    // Checking size
    byte* pointer(int minSize = 0);     // Returns ptr to storage
};
#endif
