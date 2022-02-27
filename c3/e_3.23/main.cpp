#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> vector = {21, 43, 54, 61, 41, 94, 63, 57, 91, 48};

  for (auto element : vector)
    {
      std::cout << element << " ";
    }

  std::cout << std::endl;

  for (auto it = vector.begin (); it != vector.end (); ++it)
    {
      *it *= 2;
    }

  for (auto element : vector)
    {
      std::cout << element << " ";
    }

  return 0;
}
