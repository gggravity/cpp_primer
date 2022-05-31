#include <bits/stdc++.h>
#include "quote.h"
#include "bulk_quote.h"
#include "limited_discount.h"

using namespace std;

int main ()
try
  {
    quote harry_potter_quote { "Harry Potter", 9.98 };
//    discount_quote harry_potter_discount_quote { "Harry Potter", 9.98 };
    bulk_quote harry_potter_bulk_quote { "Harry Potter", 9.98, 10, 0.5 };

    print_total(cout, harry_potter_quote, 100);
    print_total(cout, harry_potter_bulk_quote, 100);

    limited_discount harry_potter_limited_discount { "Harry Potter", 9.98, 100, 0.5 };

    print_total(cout, harry_potter_limited_discount, 100);
    print_total(cout, harry_potter_limited_discount, 200);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


