#include <iostream>
#include <vector>

using namespace std;

void print_int_vector (vector<int>::iterator begin, vector<int>::iterator end)
{
#ifndef NDEBUG
  cout << __FUNCTION__ << " begin: " << ((distance (begin, end) > 0) ? *begin : 0) << " left: " << distance (begin, end)
       << endl;
#endif
  if (begin == end)
    {
      return;
    }
  cout << *begin++ << " ";
  print_int_vector (begin, end);
}

int main()
{
#ifndef NDEBUG
  cout << "test" << endl;
#endif
  vector<int> vec {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  print_int_vector (vec.begin(), vec.end());

  return 0;
}