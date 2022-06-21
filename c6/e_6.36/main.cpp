#include <iostream>

using namespace std;

string (&func())[10];

int main()
{
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
