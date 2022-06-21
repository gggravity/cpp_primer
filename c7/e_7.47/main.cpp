#include "Sales_data.h"
#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    //    string null_isbn("9-999-99999-9"); // string constructed
    //    Sales_data item1(null_isbn); // string constructor is used.
    //    Sales_data item2("9-999-99999-9"); // string constructor is used.

    // Nothing they are explicit.

    Sales_data i;
    string s {"some string"};

    // 1) constructing a temp Sales_data for combine (don't work with explicit string constructor)
    // 2) input (s) need to be const
    // 3) Don't work combine is read only or const.

    // Sales_data &combine (const Sales_data &rhs); work best.

    i.combine (s);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
