#include <cstring>
#include <iostream>

int main()
{
  // Part 1
  //    std::string s1{"HELLO"};
  std::string s1 {"Hello, World!"};
  std::string s2 {"Hello, World!"};

  if (s1 == s2)
    {
      std::cout << "Strings are equal" << std::endl;
    }
  else
    {
      std::cout << "Strings are not equal" << std::endl;
    }

  std::cout << "-------------------" << std::endl;

  // Part 2
  //    char cs1[] = "HELLO";
  char cs1[] = "Hello, World!";
  char cs2[] = "Hello, World!";

  if (strcmp (cs1, cs2) == 0)
    {
      std::cout << "Strings are equal" << std::endl;
    }
  else
    {
      std::cout << "Strings are not equal" << std::endl;
    }

  return 0;
}
