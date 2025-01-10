#include <rational/rational.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include <doctest/doctest.h>
#include <iostream>
int main(){
  Rational a =Rational(10,6);
  Rational b =Rational(5, 3);  
  std::cout << b << " " << a << std::endl;
}