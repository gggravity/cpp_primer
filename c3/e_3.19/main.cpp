#include <iostream>
#include <vector>
int main()
{
  std::vector<int> v1 = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};

  for (auto v : v1)
    {
      std::cout << v << " ";
    }
  std::cout << std::endl << "----------" << std::endl;

  std::vector<int> v2 (10, 42);

  for (auto v : v2)
    {
      std::cout << v << " ";
    }
  std::cout << std::endl << "----------" << std::endl;

  std::vector<int> v3;

  for (int i = 0; i < 10; ++i)
    {
      v3.push_back (42);
    }

  for (auto v : v3)
    {
      std::cout << v << " ";
    }

  return 0;
}
