#include <iostream>
#include <vector>

using namespace std;

void add (int a, int b) { cout << a << " + " << b << " = " << a + b << endl; }

void subtract (int a, int b) { cout << a << " - " << b << " = " << a - b << endl; }

void multiply (int a, int b) { cout << a << " * " << b << " = " << a * b << endl; }

void divide (int a, int b) { cout << a << " / " << b << " = " << static_cast<double> (a) / b << endl; }

int main()
{
  vector<void (*) (int, int)> vec;

  vec.push_back (add);
  vec.push_back (subtract);
  vec.push_back (multiply);
  vec.push_back (divide);

  vec[0](3, 4);
  vec[1](3, 4);
  vec[2](3, 4);
  vec[3](3, 4);

  return 0;
}
