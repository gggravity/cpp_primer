#include <bits/stdc++.h>

using namespace std;

template < typename It >
auto fcn3 (It beg, It end) -> decltype(*beg)
  {
    return *beg;
  }

template < typename T1, typename T2 >
size_t sum (T1 lhs, T2 rhs)
  {
    return lhs + rhs;
  }

int main ()
try
  {
    vector<string> v { "11", "22", "33" };

    auto ret = fcn3(v.begin(), v.end());
    cout << ret << endl;

    // only legal for int and the like.

    auto summed { sum(INT64_MAX, INT64_MAX) };

    cout << summed << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


