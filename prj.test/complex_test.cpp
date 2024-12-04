// 2024 by Polevoi Dmitry under Unlicense
#include <complex/complex.hpp>//<complex.hpp>

int main() {
  Complex n1;
  Complex n2; 
  std::cin >> n1;
  std::cin >> n2;

  Complex sum = n1 + n2;

  std::cout << sum << "\n";

  Complex raz = n1 - n2;
  std::cout << raz << "\n";

  Complex umn = n1 * n2;
  std::cout << umn << "\n";

  Complex del = n1 / n2;
  std::cout << del;
  Complex g=n1/n2;
}