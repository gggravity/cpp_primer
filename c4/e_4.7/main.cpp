#include <iostream>
#include <limits>

int main()
{
  int imin = std::numeric_limits<int>::min();  // minimum value
  int imax = std::numeric_limits<int>::max();
  short smax = std::numeric_limits<short>::max();
  short short_overflow = smax + 1;

  std::cout << imin << " " << imin - 1 << std::endl;
  std::cout << imax << " " << imin + 1 << std::endl;
  std::cout << smax << " " << short_overflow << std::endl;

  return 0;
}
