#include <iostream>

using namespace std;

void swap (int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main()
{
  int a {123}, b {321};
  int *pa = &a, *pb = &b;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  cout << "Swapping .........." << endl;
  swap (*pa, *pb);

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  return 0;
}
