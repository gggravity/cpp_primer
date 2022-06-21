#include <iostream>

int largest (int i, int *pi) { return i > *pi ? i : *pi; }

int main()
{
  int a {123};
  int b {312};
  int *p = &b;

  int result = largest (a, p);

  std::cout << "The result is: " << result << std::endl;

  return 0;
}
