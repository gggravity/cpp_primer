#include <bits/stdc++.h>

using namespace std;
using namespace std::placeholders;

int main()
try
  {

    vector<int> v1 {123, 323, 543, 23, 5435, 3544, 32, 423, 132, 5435};
    vector<string> v2 {"pooh", "pooh", "pooh", "pooh", "pooh", "poooooh", "pooh", "pooh", "pooh", "pooh"};
    vector<int> v3;

    cout << count_if (v1.begin(), v1.end(), bind (greater<>(), _1, 1024)) << endl;

    cout << *find_if (v2.begin(), v2.end(), bind (not_equal_to<>(), _1, "pooh")) << endl;

    transform (v1.begin(), v1.end(), v2.begin(), bind (multiplies<>(), _1, 2));
    transform (v1.begin(), v1.end(), v2.begin(), back_inserter (v3), bind (multiplies<>(), _1, 2));

    for (auto i : v3)
      {
        cout << i << " ";
      }
    cout << endl;

    vector<int> v4 {27, 36, 22, 88, 120, 6, 8, 210};
    sort (v4.begin(), v4.end());

    size_t number {30};
    auto ret = find_if_not (v4.begin(), v4.end(), bind (modulus<>(), _1, number));

    if (ret != v4.end())
      {
        cout << *ret << " divisible by " << number << endl;
      }
    else
      {
        cout << "not divisible by any of the numbers" << endl;
      }

    vector<int> v5;
    transform (v4.begin(), v4.end(), back_inserter (v5), bind (modulus<>(), _1, number));

    for (size_t i {0}; i < v5.size(); ++i)
      {
        cout << setw (3) << v4[i] << " " << (v5[i] ? "false" : "true") << endl;
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
