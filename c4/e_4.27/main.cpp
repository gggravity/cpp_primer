#include <bitset>
#include <iostream>

int main()
{
  unsigned long ul1 = 3, ul2 = 7;

  std::cout << std::bitset<8> (ul1) << std::endl;
  std::cout << std::bitset<8> (ul2) << std::endl;

  std::cout << std::bitset<8> (ul1 & ul2) << std::endl;
  std::cout << (ul1 & ul2) << std::endl;

  std::cout << std::bitset<8> (ul1 | ul2) << std::endl;
  std::cout << (ul1 | ul2) << std::endl;

  std::cout << (ul1 && ul2) << std::endl;

  std::cout << (ul1 || ul2) << std::endl;

  return 0;
}
