#include <iostream>
#include <vector>

int main()
{
  std::vector<std::string> vector;
  std::string string;

  while (std::getline (std::cin, string))
    {
      if (string == ".")
        {
          break;
        }
      vector.push_back (string);
    }
  for (auto it = vector.begin(); it != vector.end(); ++it)
    {
      for (char &c : *it)
        {
          c = toupper (c);
        }
    }
  for (const auto &element : vector)
    {
      std::cout << element << " ";
    }

  return 0;
}
