#include <iostream>

void reset (int &number)
{
  number = 0;
}

int main ()
{
  int a = 123;
  std::cout << "a = " << a << std::endl;
  reset(a);
  std::cout << "a = " << a << std::endl;

  return 0;
}
