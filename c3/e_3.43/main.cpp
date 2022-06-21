#include <iostream>

int main()
{
  int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
  // Range for

  for (const int (&i)[4] : ia)
    {
      for (const int &j : i)
        {
          std::cout << j << " ";
        }
      std::cout << std::endl;
    }

  std::cout << "--------------\n";

  // for loop

  for (int i = 0; i != 3; i++)
    {
      for (int j = 0; j != 4; j++)
        {
          std::cout << ia[i][j] << " ";
        }
      std::cout << std::endl;
    }

  std::cout << "--------------\n";

  // pointer

  for (int (*p)[4] = std::begin (ia); p != std::end (ia); ++p)
    {
      for (int *q = std::begin (*p); q != std::end (*p); ++q)
        {
          std::cout << *q << " ";
        }
      std::cout << std::endl;
    }

  return 0;
}
