#include "Vector.h"
#include "string_vector.h"
#include <bits/stdc++.h>

using namespace std;

template <typename T, typename... Args> inline auto MakeShared (Args &&...args)
{
  shared_ptr<T> ret (new T (forward<Args> (args)...));
  return ret;
}

int main()
try
  {
    string_vector sv;

    sv.emplace_back ("ABC");
    sv.emplace_back ("DEF");
    sv.emplace_back ("GHI");

    for (auto &i : sv)
      {
        cout << i << " ";
      }
    cout << endl;

    Vector<string> v;

    v.emplace_back ("ABC");
    v.emplace_back ("DEF");
    v.emplace_back ("GHI");

    for (auto &i : v)
      {
        cout << i << " ";
      }
    cout << endl;

    auto sv_pointer_1 {MakeShared<string_vector> (sv)};
    auto sv_pointer_2 {MakeShared<Vector<string>> (v)};

    for (auto &i : *sv_pointer_1)
      {
        cout << i << " ";
      }
    cout << endl;

    for (auto &i : *sv_pointer_2)
      {
        cout << i << " ";
      }
    cout << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
