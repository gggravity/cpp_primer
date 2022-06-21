#include <iostream>

using namespace std;

void f() { cout << "Calling: f ()" << endl; }
void f (int) { cout << "Calling: f (int)" << endl; }
void f (int, int) { cout << "Calling: f (int, int)" << endl; }
void f (double, double = 3.14) { cout << "Calling: f (double, double = 3.14)" << endl; }

int calc (char *, char *);
int calc (const char *, const char *);

int main()
{
  //  f (2.56, 41);
  f (42);
  f (42, 0);
  f (2.56, 3.14);

  return 0;
}
