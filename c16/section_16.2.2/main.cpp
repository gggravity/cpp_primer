#include <bits/stdc++.h>

using namespace std;

template <typename T, typename U> auto compare (T t, U u)
{
  if (t < u)
    {
      return -1;
    }
  if (u < t)
    {
      return 1;
    }
  return 0;
}

int main()
try
  {
    int a;
    double b;
    auto ret = max (a, int (b));

    cout << ret << endl;

    auto ptr {make_shared<int> (int {999})};

    cout << *ptr << endl;

    auto comp {compare ("string", "another")};

    cout << comp << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
