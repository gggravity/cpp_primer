#include "String.h"
#include <bits/stdc++.h>

using namespace std;

int f() { return 1; }

int main()
try
  {

    // e 13.46
    vector<int> vi (100);
    int &&r1 = f();
    int &r2 = vi[0];
    int &r3 = r1;
    int &&r4 = vi[0] * f();

    // e 13.47
    String s1 ("some string");

    String s2 {s1};

    String s3;
    s3 = s2;

    // 13.48

    vector<String> v;

    for (size_t i {0}; i < 3; ++i)
      {
        //        v.push_back(String(to_string(i)));
        v.emplace_back (to_string (i));
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
