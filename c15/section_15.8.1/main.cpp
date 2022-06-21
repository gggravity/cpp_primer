#include "basket.h"
#include "bulk_quote.h"
#include "limited_discount.h"
#include "quote.h"
#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    basket b;

    b.add_item (make_shared<quote> ("123", 45));
    b.add_item (make_shared<bulk_quote> ("345", 10, 3, 0.5));
    b.add_item (make_shared<quote> ("345", 45));
    b.add_item (make_shared<quote> ("345", 45));
    b.add_item (make_shared<quote> ("345", 45));
    b.add_item (make_shared<quote> ("345", 45));
    b.add_item (make_shared<quote> ("345", 45));
    //    b.add_item(make_shared<bulk_quote>("345", 20, 3, 0));
    //    b.add_item(make_shared<bulk_quote>("345", 30, 3, 0));
    //    b.add_item(make_shared<bulk_quote>("345", 40, 3, 0));
    //    b.add_item(make_shared<bulk_quote>("345", 50, 3, 0));

    b.add_item (bulk_quote ("Harry Potter 1", 9.98, 1, 0.5));
    b.add_item (quote ("Harry Potter 1", 9.98));
    b.add_item (quote ("Harry Potter 1", 9.98));
    b.add_item (quote ("Harry Potter 1", 9.98));
    b.add_item (quote ("Harry Potter 1", 9.98));

    b.add_item (bulk_quote ("Harry Potter 2", 9.98, 1, 0.3));
    b.add_item (quote ("Harry Potter 2", 9.98));
    b.add_item (quote ("Harry Potter 2", 9.98));
    b.add_item (quote ("Harry Potter 2", 9.98));
    b.add_item (quote ("Harry Potter 2", 9.98));

    b.add_item (bulk_quote ("Harry Potter 3", 14.98, 1, 0.2));
    b.add_item (quote ("Harry Potter 3", 14.98));
    b.add_item (quote ("Harry Potter 3", 14.98));
    b.add_item (quote ("Harry Potter 3", 14.98));
    b.add_item (quote ("Harry Potter 3", 14.98));

    b.total_receipt (cout);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
