#include "has_ptr.h"
#include <bits/stdc++.h>

using namespace std;

void print_vector (vector<has_ptr> v)
{
  for (auto iter {v.begin()}; iter < v.end() - 1; ++iter)
    {
      cout << *iter << " <= " << *(iter + 1) << " = " << (*iter <= *(iter + 1)) << endl;
    }
}

int main()
try
  {
    random_device rd;
    default_random_engine eng (rd());
    uniform_int_distribution<int> dist (48, 123);

    cout << boolalpha;
    has_ptr h1 {"A"};
    has_ptr h2 {h1};
    h2.set_ps (new string ("B"));

    cout << h1 << endl;
    cout << h2 << endl;
    cout << (h1 < h2) << endl;

    vector<has_ptr> v;
    for (int i {0}; i < 10; i++)
      {
        auto c = ( char ) dist (eng);
        v.emplace_back (string (1, c));
      }

    print_vector (v);
    sort (v.begin(), v.end());
    cout << "-----------" << endl;
    print_vector (v);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
