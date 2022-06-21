#include <iostream>

using namespace std;

int error_msg (initializer_list<int> list)
{
  int sum {0};

  for (auto element : list)
    {
      sum += element;
    }
  return sum;
}

int main()
{
  initializer_list<int> lst {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  cout << "The sum of the initializer_list = " << error_msg (lst) << std::endl;

  return 0;
}
