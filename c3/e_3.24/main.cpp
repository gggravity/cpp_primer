#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vector = {5, 9, 6, 7, 8, 5, 6, 7, 9, 8};

  for (auto v : vector)
    {
      std::cout << v << "  ";
    }

  std::cout << std::endl;

  for (auto it = vector.begin(); it != vector.end(); ++it)
    {
      if (it == vector.end() - 1)
        {
          std::cout << *it;
        }
      else
        {
          std::cout << *it + *(it + 1) << " ";
        }
    }

  return 0;
}
