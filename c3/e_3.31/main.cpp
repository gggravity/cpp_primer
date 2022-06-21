#include <iostream>

int main()
{
  int array[10];

  for (int i = 0; i <= 10; i++)
    {
      array[i] = i;
    }

  for (auto a : array)
    {
      std::cout << a << " ";
    }

  return 0;
}