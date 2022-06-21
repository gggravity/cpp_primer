#include <iostream>
#include <vector>

using namespace std;

void check_vector_int (vector<int> v)
{
  if (v.begin() != v.end())
    {
      for (auto it = v.cbegin(); it != v.cend(); ++it)
        {
          cout << *it << " ";
        }
      cout << " - The length is: " << v.size() << endl;
    }
  else
    {
      cout << "The vector is empty" << endl;
    }
}

void check_vector_string (vector<string> v)
{
  if (v.begin() != v.end())
    {
      for (auto it = v.cbegin(); it != v.cend(); ++it)
        {
          cout << *it << " ";
        }
      cout << " - The length is: " << v.size() << endl;
    }
  else
    {
      cout << "The vector is empty" << endl;
    }
}

int main()
{
  vector<int> v1;
  check_vector_int (v1);

  vector<int> v2 (10);
  check_vector_int (v2);

  vector<int> v3 (10, 42);
  check_vector_int (v3);

  vector<int> v4 {10};
  check_vector_int (v4);

  vector<int> v5 {10, 42};
  check_vector_int (v5);

  vector<string> v6 {10};
  check_vector_string (v6);

  vector<string> v7 {10, "Hi"};
  check_vector_string (v7);

  return 0;
}
