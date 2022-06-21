#include "Str_blob.h"
#include <bits/stdc++.h>

using namespace std;

int main()
try
  {

    Str_blob b1;
    {
      Str_blob b2 = {"a", "an", "the"};
      b1 = b2;
      b2.push_back ("about");
    }
    cout << b1.size() << endl;
    //    cout << b2.size() << endl; // b2 is out of scope and don't exist anymore.

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
