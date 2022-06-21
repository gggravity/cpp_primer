#include <bits/stdc++.h>

using namespace std;

template <typename T, typename... Args> void foo (const T &t, const Args &...rest)
{
  cout << "sizeof .. Args: " << sizeof...(Args) << endl;
  cout << "sizeof .. rest: " << sizeof...(rest) << endl;
}

template <typename... Args> void g (Args... args)
{
  cout << sizeof...(Args) << endl;
  cout << sizeof...(args) << endl;
}

int main()
try
  {
    int i {0};
    double d {3.14};
    string s {"how now brown cow"};

    foo (i, s, 42, d);
    foo (s, 42, "hi");
    foo (d, s);
    foo ("hi");

    //    g(i, s, 42, d);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
