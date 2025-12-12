#include <iostream>

#include "string.h"

int main() {
  String const hello("hello");
  String const ell = hello[1][4];
  ell.Print();
  return 0;
}