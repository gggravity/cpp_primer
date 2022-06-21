#include <iostream>

int main()
{
  int i = 0;
  int *p = &i;

  std::cout << "p = " << p << " *p = " << *p << std::endl;

  if (p)  // p have an address
    {
      std::cout << "if (p)" << std::endl;
    }
  if (*p)  // if the value is not 0
    {
      std::cout << "if (*p)" << std::endl;
    }
  return 0;
}
