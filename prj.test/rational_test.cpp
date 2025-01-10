#include <rational/rational.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include <doctest/doctest.h>
#include <iostream>
int main(){
  Rational a(17, 3);  
  a += 1;
  std::cout << " " << a << std::endl;
}