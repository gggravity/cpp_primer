#include <iostream>

int main()
{
  int i = 0, &r = i;
  const int ci = i, &cr = ci;

  auto a = r;         // int
  auto b = ci;        // int
  auto c = cr;        // int
  auto d = &i;        // int *
  auto e = &ci;       // const int *
  const auto f = ci;  // const int
  auto &g = ci;       // const int &

  a = 42;
  std::cout << "a = " << a << std::endl;

  b = 42;
  std::cout << "b = " << b << std::endl;

  c = 42;
  std::cout << "c = " << c << std::endl;

  //    d = 42;
  //    std::cout << "d = " << d << std::endl;
  //
  //    e = 42;
  //    std::cout << "e = " << e << std::endl;
  //
  //    g = 42;
  //    std::cout << "g = " << g << std::endl;

  return 0;
}
