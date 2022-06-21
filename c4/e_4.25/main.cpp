#include <bitset>
#include <iostream>

int main()
{

  int test = ~'q' << 6;
  std::bitset<8> x ('q');
  std::bitset<32> y (~'q' << 6);
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  std::cout << test << std::endl;
  return 0;
}
