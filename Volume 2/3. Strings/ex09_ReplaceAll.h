//: C03:ReplaceAll.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#ifndef REPLACEALL_H
#define REPLACEALL_H
#include <string>

std::string& replaceAll(std::string& context,
  const std::string& from, const std::string& to);
#endif // REPLACEALL_H ///:~
