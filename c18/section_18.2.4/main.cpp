#include <bits/stdc++.h>

using namespace std;

namespace primerLib
{
void compute();

void compute (const void *) { cout << "void compute (const void *)" << endl; }
}  // namespace primerLib

using primerLib::compute;

void compute (int) { cout << "void compute (int)" << endl; }

void compute (double, double = 3.4);

void compute (char *, char * = 0);

void f()
{
  compute (0);  // uses void compute (int);
}

int main()
{
  //    using primerLib::compute; // same

  f();

  return 0;
}
