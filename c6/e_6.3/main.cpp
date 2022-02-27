#include <iostream>

using namespace std;

int fact (int number)
{
  int result{1};

  while (number > 1)
    {
      result *= number--;
    }

  return result;
}

int main ()
{
  cout << fact (5);

  return 0;
}
