/**
Modify SuperVar so that there are #ifdefs around all the vartype code as described
in the section on enum. Make vartype a regular and public enumeration (with no instance)
and modify print( ) so that it requires a vartype argument to tell it what to do.
**/

#include <iostream>
#define CHECK_VARTYPE

using namespace std;

enum VARTYPES {
    character,
    integer,
    floating_point
};

class SuperVar {
	union {
		char c;
		int i;
		float f;
	};

#ifdef CHECK_VARTYPE
    VARTYPES vartype;
#endif

public:
	SuperVar(char ch);
	SuperVar(int ii);
	SuperVar(float ff);
	void print(VARTYPES vartype);
};

SuperVar::SuperVar(char ch) {
#ifdef CHECK_VARTYPE
	vartype = character;
#endif
	c = ch;
}

SuperVar::SuperVar(int ii) {
#ifdef CHECK_VARTYPE
	vartype = integer;
#endif
	i = ii;
}

SuperVar::SuperVar(float ff) {
#ifdef CHECK_VARTYPE
	vartype = floating_point;
#endif
	f = ff;
}

void SuperVar::print(VARTYPES print_vartype) {
#ifdef CHECK_VARTYPE
	if( vartype != print_vartype ) {
		cout << "Bad type." << endl;
		return;
	}
#endif
    switch (print_vartype) {
        case character:
            cout << "Character: " << c << endl;
            break;
        case integer:
            cout << "Integer: " << i << endl;
            break;
        case floating_point:
            cout << "Float: " << f << endl;
            break;
      }
}

int main() {

	SuperVar A('c'), B(12), C(1.44F);

	A.print(character);
	B.print(integer);
	C.print(floating_point);

return 0;
}
