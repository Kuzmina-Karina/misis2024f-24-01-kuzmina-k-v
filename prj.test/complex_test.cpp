// 2024 by Polevoi Dmitry under Unlicense
#include <complex/complex.hpp>//<complex.hpp>

int main() {
  Complex n1;
  Complex n3;
  double n2;
  std::cin >> n1;
  std::cin >> n2;
  std::cin >> n3;

  if (n1==n3){
    std::cout << '1' << "\n";
  }
  else{
    std::cout << '0' << "\n";
  }

  Complex sum = n1 + n2;
  std::cout << sum << "\n";

  Complex raz = n1 - n2;
  std::cout << raz << "\n";

  Complex umn = n1 * n2;
  std::cout << umn << "\n";

  Complex del = n1 / n2;
  std::cout << del;
  Complex g=n1/n2;
  std::cout <<1;
  std::cout <<2;
}