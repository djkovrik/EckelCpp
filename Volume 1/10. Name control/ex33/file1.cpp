#include "Mirror.h"

Mirror& m1() {
    static Mirror m1;
    return m1;
}
