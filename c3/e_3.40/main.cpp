#include <cstring>
#include <iostream>

int main()
{
  char cs1[] = "Hello, World!";
  char cs2[] = "Hello World";

  std::cout << "cs1 = " << cs1 << std::endl;
  std::cout << "cs2 = " << cs2 << std::endl;

  int len1 = std::end (cs1) - std::begin (cs1) - 1;
  int len2 = std::end (cs2) - std::begin (cs2) - 1;
  int len = len1 + len2 + 1;

  std::cout << "len1 = " << len1 << std::endl;
  std::cout << "len2 = " << len2 << std::endl;
  std::cout << "len = " << len << std::endl;

  char concat[len];

  strcpy (concat, cs1);
  strcat (concat, " ");
  strcat (concat, cs2);

  std::cout << "concat = " << concat << std::endl;

  return 0;
}
