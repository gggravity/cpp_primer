#include <iostream>

class X;

class Y;

class X
      {
            Y *y_prt {};
      };

class Y
      {
            X x {};
      };

int main ()
  {
    X x;
    Y y;

    std::cout << "Hello, World!" << std::endl;
    return 0;
  }
