#include "Sales_data.h"
#include "String.h"
#include "employee.h"
#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    // e 14.6
    Sales_data sd {"ABC-123-DEF", 5, 23.98};

    cout << sd << endl;

    // e 14.7
    // need c++ <= 17
    String s {"test string"};

    cout << s << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
