#include <bits/stdc++.h>
#include "quote.h"
#include "bulk_quote.h"
#include "limited_discount.h"

using namespace std;

int main ()
try
  {
    quote harry_potter_quote { "Harry Potter", 9.98 };
    quote new_quote { harry_potter_quote };
    quote another;
    another = new_quote;

    quote q1 = std::move(harry_potter_quote);
    quote q2;
    q2 = std::move(harry_potter_quote);

    cout << "---------------------" << endl;

    bulk_quote harry_potter_bulk { "Harry Potter", 9.98, 100, 0.5 };
    bulk_quote new_bulk_quote { harry_potter_bulk };
    bulk_quote another_bulk;
    another_bulk = new_bulk_quote;

    bulk_quote q1bulk = std::move(harry_potter_bulk);
    bulk_quote q2bulk;
    q2bulk = std::move(harry_potter_bulk);

    cout << "---------------------" << endl;

    limited_discount harry_potter_limited { "Harry Potter", 9.98, 100, 0.5 };
    limited_discount new_limited { harry_potter_limited };
    limited_discount another_limited;
    another_limited = new_limited;

    limited_discount q1limited = std::move(harry_potter_limited);
    limited_discount q2limited;
    q2limited = std::move(harry_potter_limited);

    cout << "---------------------" << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


