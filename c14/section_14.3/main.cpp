#include "Sales_data.h"
#include "employee.h"
#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    // e 14.13

    Sales_data sd1 {"XXX-123-QQQ", 12, 123.4};
    Sales_data sd2 {"BBB-312-AAQ", 3, 12.4};
    Sales_data sd3 {sd1};

    cout << boolalpha;
    cout << (sd1 == sd2) << endl;
    cout << (sd1 != sd2) << endl;
    cout << (sd1 == sd3) << endl;

    // e 14.14
    // extra temporary variables are needed with the other approach.

    // e 14.15

    employee frank {"frank", "North-pole", "Greenland", "+299-123-456", 1};
    employee smilla {"Smilla", "South-pole", "Argentina", "+54-987-654-321", 2};

    cout << (frank == smilla) << endl;
    cout << (frank != smilla) << endl;

    employee fake_frank {frank};

    cout << (frank == fake_frank) << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
