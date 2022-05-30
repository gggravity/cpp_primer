#include <bits/stdc++.h>
#include "quote.h"
#include "bulk_quote.h"
#include "discount_quote.h"

using namespace std;

int main ()
try
  {
    quote hp1 { "Harry Potter - Part 1", 9.98 };
    bulk_quote hp1bulk {"Harry Potter - Part 1", 9.98 , 10, 0.1};

    print_total(cout, hp1, 10);
    print_total(cout, hp1bulk, 10);

    discount_quote hp1discounted {"Harry Potter - Part 1", 9.98};

    print_total(cout, hp1discounted, 10);
    print_total(cout, hp1discounted, 50);
    print_total(cout, hp1discounted, 100);
    print_total(cout, hp1discounted, 500);
    print_total(cout, hp1discounted, 1000);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


