#include <bits/stdc++.h>
#include "SalesData.hpp"

using namespace std;

int main ()
  {

    SalesData item1 { "123-XXX", 1, 10 };
    SalesData item2 { "321-XXX", 1, 10 };
    SalesData sum;

    try
      {
        sum = item1 + item2;
      }
    catch (const isbn_mismatch &e)
      {
        cerr << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")" << endl;
      }

    return 0;
  }
