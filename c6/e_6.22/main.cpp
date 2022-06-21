#include <iostream>

using namespace std;

void swap_pointer (int *&p1, int *&p2)
{
  int *temp = p1;
  p1 = p2;
  p2 = temp;
}

int main()
{
  int a {123}, b {321};
  int *pa = &a, *pb = &b;

  cout << "*pa = " << *pa << " *pb = " << *pb << endl;
  cout << "pa = " << pa << " pb = " << pb << endl;
  cout << "-------- swapping --------" << endl;
  swap_pointer (pa, pb);
  cout << "*pa = " << *pa << " *pb = " << *pb << endl;
  cout << "pa = " << pa << " pb = " << pb << endl;

  return 0;
}
