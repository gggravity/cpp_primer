#include <iostream>

using namespace std;

void print (const int *beg, const int *end)
{
  while (beg != end)
    {
      cout << *beg++ << " ";
    }
}

void print (const int ia[], size_t size)
{
  for (size_t i = 0; i != size; ++i)
    {
      cout << ia[i] << " ";
    }
}

int main()
{
  int i = 0, j[2] = {0, 1};

  cout << "version 1: ";
  print (begin (j), end (j));
  cout << endl;

  cout << "version 2: ";
  print (j, size (j));
  cout << endl;

  return 0;
}
