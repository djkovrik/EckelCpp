#include "Mirror.h"

extern Mirror& m2();

Mirror& m3() {
    static Mirror m3(m2());
    return m3;
}
