/**
Make a new version of ConstPointer.cpp called ConstReference.cpp which demonstrates references instead of pointers
**/
void t(int&) {}

void u(const int& cip) {
    int i = cip; // OK -- copies value
}

const int& w() {
    static int i;
    const int& ir = i;
    return ir;
}

int main() {
    int x = 0;
    int& ip = x;
    const int& cip = x;
    t(ip);
    u(ip);
    u(cip);
    const int& cip2 = w();
}
