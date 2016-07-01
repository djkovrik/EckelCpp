/**
Modify ConstPointer.cpp removing comments on the error-causing lines
one at a time, to see what error messages your compiler generates.
**/
void t(int*) {}

void u(const int* cip) {
//!  *cip = 2; // Illegal -- modifies value
//!  error: assignment of read-only location '* cip'

  int i = *cip; // OK -- copies value
//!  int* ip2 = cip; // Illegal: non-const
//!  error: invalid conversion from 'const int*' to 'int*'
}

const char* v() {
  // Returns address of static character array:
  return "result of function v()";
}

const int* const w() {
  static int i;
  return &i;
}

int main() {
  int x = 0;
  int* ip = &x;
  const int* cip = &x;
  t(ip);  // OK
//!  t(cip); // Not OK
//!  error: invalid conversion from 'const int*' to 'int*'

  u(ip);  // OK
  u(cip); // Also OK
//!  char* cp = v(); // Not OK
//!  error: invalid conversion from 'const char*' to 'char*'

  const char* ccp = v(); // OK
//!  int* ip2 = w(); // Not OK
//!  error: invalid conversion from 'const int*' to 'int*'

  const int* const ccip = w(); // OK
  const int* cip2 = w(); // OK
//!  *w() = 1; // Not OK
//!  error: assignment of read-only location '* w()'
}
