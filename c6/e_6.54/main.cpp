#include <iostream>
#include <vector>

using namespace std;

int test (int, int);

int main()
{
  vector<int (*) (int, int)> vec;

  for (int i = 0; i != 10; ++i)
    {
      vec.push_back (test);
      auto result = vec[i](i, i);
      cout << "The result is: " << result << endl;
    }

  return 0;
}

int test (int a, int b)
{
  cout << "Calling test function...\n";

  return a + b;
}
