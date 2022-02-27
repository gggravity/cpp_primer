#include <iostream>
#include <vector>
int main ()
{
  int i = 0;
  std::vector<int> v;

  while (std::cin >> i)
    {
      v.push_back (i);
    }

  std::cout << "--- the values in the vector are:" << std::endl;
  for (int value : v)
    {
      std::cout << value << " ";
    }

  return 0;
}
