#include "video.h"

using std::cout;
using std::endl;

void Video::print() {

    cout << "ID: " << getId()
         << "\nLength: " << getLength()
         << "\nPrice: " << getPrice()
         << "\nName: " << getName()
         << "\n----------" << endl;

}
