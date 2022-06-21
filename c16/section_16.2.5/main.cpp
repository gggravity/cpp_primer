#include <bits/stdc++.h>

using namespace std;

template <typename T> void g (T &&val)
{
  cout << boolalpha;
  cout << is_const<T>::value << " " << typeid (val).name() << endl;

  //    vector<T> v;
}

int main()
try
  {
    int i {0};
    const int ci {i};

    g (i);
    g (ci);
    g (i * ci);

    g (i = ci);

    g (42);
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
