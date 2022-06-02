#include <bits/stdc++.h>
#include "quote.h"
#include "bulk_quote.h"
#include "limited_discount.h"

using namespace std;

int main ()
try
  {
    vector<quote> b;

    b.emplace_back("Harry Potter", 10.0);
    b.push_back(bulk_quote("Harry Potter", 10.0, 10, 0.5));

    for (auto &item : b)
      {
        print_total(cout, item, 100);
      }

    for (auto &item : b)
      {
        print_total(cout, item, 5);
      }
      // error in this version... quantity, discount from the derived class are missing.

    vector<unique_ptr<quote>> basket;

    basket.emplace_back(make_unique<quote>("Harry Potter", 10.0));
    basket.emplace_back(make_unique<bulk_quote>("Harry Potter", 10.0, 10, 0.5));

    for (auto &item : basket)
      {
        print_total(cout, *item, 100);
      }

    for (auto &item : basket)
      {
        print_total(cout, *item, 5);
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


