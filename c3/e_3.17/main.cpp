#include <iostream>
#include <vector>

int main()
{
  std::vector<std::string> vector;
  std::string string;

  while (std::cin >> string)
    {
      if (string == ".")
        {
          break;
        }
      vector.push_back (string);
    }

  for (auto &s : vector)
    {
      for (auto &c : s)
        {
          c = toupper (c);
        }
    }

  for (auto word : vector)
    {
      std::cout << word << " ";
    }

  return 0;
}
