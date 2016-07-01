//: C06:PrintSequence.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Prints the contents of any sequence.
#ifndef PRINTSEQUENCE_H
#define PRINTSEQUENCE_H
#include <algorithm>
#include <iostream>
#include <iterator>

template<typename Iter>
void print(Iter first, Iter last, const char* nm = "",
           const char* sep = "\n",
           std::ostream& os = std::cout) {
  if(nm != 0 && *nm != '\0')
    os << nm << ": " << sep;
  typedef typename 
    std::iterator_traits<Iter>::value_type T;
  std::copy(first, last, 
            std::ostream_iterator<T>(std::cout, sep));
  os << std::endl;
}
#endif // PRINTSEQUENCE_H ///:~
