#include <iostream>

int main()
{
  const int i = 42;
  auto j = i;
  const auto &k = i;
  auto *p = &i;
  const int &k2;
  k2 = i;
  const auto j2 = i;

  std::cout << "Hello, World!" << std::endl;
  return 0;
}
