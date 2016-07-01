#ifndef EXTERNAL_H_INCLUDED
#define EXTERNAL_H_INCLUDED

#include "Stack.h"
#include "Stash.h"
#include <iostream>

struct ExternalStruct {

    ExternalStruct() { stashStack.initialize(); reverseStack.initialize(); }

    Stack stashStack;
    Stack reverseStack;

    void add_stash(Stash* dat){ stashStack.push(dat); }
    Stash* remove_stash()     { return (Stash*)reverseStack.pop(); }

    void reverse() {
        Stash *sPointer = 0;
        while((sPointer = (Stash*)stashStack.pop()) != 0)
            reverseStack.push(sPointer);
    std::cout << "Reversed." << std::endl;
    }
};


#endif // EXTERNAL_H_INCLUDED
