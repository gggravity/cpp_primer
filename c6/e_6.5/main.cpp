#include <iostream>

int absolute (int i) { return abs (i); }

int main()
{
  std::cout << absolute (-10) << std::endl;

  return 0;
}
