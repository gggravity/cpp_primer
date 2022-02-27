#include <iostream>

int counter ()
{
  static int counter{-1};

  return ++counter;
}

int main ()
{
  for (int i = 0; i != 10; i++)
    std::cout << counter () << std::endl;

  return 0;
}
