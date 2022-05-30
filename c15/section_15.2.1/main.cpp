#include <bits/stdc++.h>
#include "quote.h"

using namespace std;

int main ()
try
  {
    quote hp1 { "Harry Potter - Part 1", 9.98 };

    print_total(cout, hp1, 10);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


