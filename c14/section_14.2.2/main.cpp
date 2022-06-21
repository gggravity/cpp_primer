#include "Sales_data.h"
#include "employee.h"
#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    // e 14.9
    istringstream iss {"{ XXX-123-YYY 9 0.9 }"};
    Sales_data sd;

    iss >> sd;
    cout << sd;

    // e 14.10
    istringstream iss_14_10a {"{ 0-201-99999-9 10 24.95 }"};
    istringstream iss_14_10b {"{ 10 24.95 0-201-99999-9 }"};
    Sales_data e14_10a;
    Sales_data e14_10b;

    iss_14_10a >> e14_10a;
    //    iss_14_10b >> e14_10b;

    cout << e14_10a << endl;
    //    cout << e14_10b << endl;
    // the last one don't work, it fails when trying to read the last two values (int and double)
    // without hte sanity check in the operator >> it gives wrong values.

    // e 14.11

    employee e;

    istringstream iss_e_14_11 {"Peter Swea Sweden +123-321-321 1"};
    iss_e_14_11 >> e;
    cout << e << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
