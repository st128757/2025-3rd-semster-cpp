#include <iostream>

#include "string.h"

int main() {
  String const hello("hello");
  String const ell = hello[1][4];
  ell.Print();
  String result = ell;
  String to_append = " there!";
  result.append(to_append);
  return 0;
}
