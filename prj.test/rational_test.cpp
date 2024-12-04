// 2024 by Polevoi Dmitry under Unlicense
#include <rational/rational.hpp>//<complex.hpp>

int main() {
  Rational n1;
  Rational n3; 
  //int32_t n3;
  std::cin >> n1 >> n3;
  //std::cin >> n2;
  //std::cin >> n3;

  Rational sum = n1 + n3;
  std::cout << sum << "\n";

  Rational raz = n1 - n3;
  std::cout << raz << "\n";

  Rational umn = n1 * n3;
  std::cout << umn << "\n";

  Rational del = n1 / n3;
  std::cout << del;
  Rational g=n1/n3;

  if(n3<n1){
    std::cout <<"YES";
  }
  else{
    std::cout << "NO";
  }
}