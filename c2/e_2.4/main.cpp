#include <iostream>

int main()
{
  unsigned u = 10, u2 = 42;
  std::cout << u2 - u << std::endl;  // 42 - 10 = 32
  std::cout << u - u2 << std::endl;  // Wrap

  int i = 10, i2 = 42;
  std::cout << i2 - i << std::endl;  // 42 - 10 = 32
  std::cout << i - i2 << std::endl;  // 10 - 42 = - 32

  std::cout << i - u << std::endl;  // 10 - 10 = 0
  std::cout << u - i << std::endl;  // 10 - 10 = 0

  return 0;
}
