#include <bits/stdc++.h>

using namespace std;

template < typename F, typename T1, typename T2 >
auto flip (F f, T1 &&t1, T2 &&t2)
  {
    f(std::forward<T2>(t2), std::forward<T1>(t1));
  }

auto func (int v1, int &v2)
  {
    cout << v1 << " " << ++v2 << endl;
  }

int main ()
try
  {
    int v1 { 1 };
    int v2 { 2 };

    flip(func, v1, v2);

    cout << v1 << " " << v2 << endl;

    flip(func, v2, v1);

    cout << v1 << " " << v2 << endl;

  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


