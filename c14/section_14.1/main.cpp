#include <bits/stdc++.h>
#include "Sales_data.h"

using namespace std;

int main ()
try
  {
    Sales_data sales_data1 { "1234567", 10, 1000.00 };
    Sales_data sales_data2 { "1234567", 1, 44.00 };
    Sales_data sales_data3 { "123-456-7", 1, 666 };

    cout << sales_data1 << endl;
    cout << sales_data2 << endl;
    cout << sales_data3 << endl;

    cout << sales_data1 + sales_data2 << endl;
    sales_data1 += sales_data2;
    cout << sales_data1 << endl;
    cout << sales_data1 + sales_data3 << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
