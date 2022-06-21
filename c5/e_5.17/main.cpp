#include <iostream>
#include <vector>

using namespace std;

string &getString (const vector<int> &v2, const vector<int> &v1, string &test_result, int i);

int main()
{
  vector<int> v2 {0, 1, 1, 2};
  vector<int> v1 {0, 1, 1, 2, 3, 5, 8};
  string test_result = "true";

  if (v1.size() <= v2.size())
    {
      for (int i = 0; i != v1.size(); ++i)
        {
          test_result = getString (v2, v1, test_result, i);
        }
    }
  else
    {
      for (int i = 0; i != v2.size(); ++i)
        {
          test_result = getString (v2, v1, test_result, i);
        }
    }

  cout << "Test result: " << test_result << endl;

  return 0;
}
string &getString (const vector<int> &v2, const vector<int> &v1, string &test_result, int i)
{
  if (v1[i] != v2[i])
    {
      test_result = "false";
    }
  return test_result;
}
