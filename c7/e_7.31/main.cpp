#include <iostream>

class X;
class Y;


class X {
  [[maybe_unused]] Y *yp = nullptr;
};

class Y {
  [[maybe_unused]] X x;
};

int main ()
{
  X x;
  Y y;

  std::cout << "Hello, World!" << std::endl;
  return 0;
}
