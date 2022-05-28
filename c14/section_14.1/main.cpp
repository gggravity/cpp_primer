#include <bits/stdc++.h>
#include "Sales_data.h"
#include "employee.h"

using namespace std;

int main ()
try
  {
//    Sales_data sales_data1 { "1234567", 10, 1000.00 };
//    Sales_data sales_data2 { "1234567", 1, 44.00 };
//    Sales_data sales_data3 { "123-456-7", 1, 666 };
//
//    cout << sales_data1 << endl;
//    cout << sales_data2 << endl;
//    cout << sales_data3 << endl;
//
//    cout << sales_data1 + sales_data2 << endl;
//    sales_data1 += sales_data2;
//    cout << sales_data1 << endl;
//    cout << sales_data1 + sales_data3 << endl;

//    Sales_data sales_data_input_test;
//
//    istringstream iss { "{ 666-XYZ-ABC 6 66.66 }" };
//
//    iss >> sales_data_input_test;
//    cout << sales_data_input_test << endl;

    employee frank {"frank", "North-pole", "Greenland", "+299-123-456", 1};
    employee smilla {"Smilla", "South-pole", "Argentina", "+54-987-654-321", 2};

    cout << boolalpha;
    cout << frank << endl;
    cout << smilla << endl;
    cout << (frank == smilla) << endl;
    cout << (frank != smilla) << endl;

    employee mrx;
    istringstream iss {"MrX Unknown Unknown +000-000-000 1"};
    iss >> mrx;
    cout << mrx;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
