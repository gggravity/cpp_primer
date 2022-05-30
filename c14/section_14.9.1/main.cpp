#include <bits/stdc++.h>
#include "Sales_data.h"
#include "employee.h"

using namespace std;

struct Integral
    {
        operator const int ();

        operator int () const;
    };

int main ()
try
  {

    Sales_data sd { "123-123-XXX-QWE", 10, 58.50 };

    string sd_string { sd };

    cout << sd_string << endl;

    // e 14.46
    // should be explicit, the compiler says so :-)
    // it's a bad idea, it should be more explicit what is going on.

    // e 14.47
    // first is non const and convert to const int.
    // second is const and convert to not const.

    // e 14.48
    // it shouldn't have one.

    // e 14.49

    employee frank { "Frankenstein", "Transylvania", "Garden of Eden", "+1 666", 666 };
    employee franz { "Franz Ferdinand", "Sarajevo", "Austria-Hungary", "+1 123-123-123", 1 };

    cout << boolalpha;
    cout << frank << endl;
    cout << franz << endl;
    cout << frank.name << ": " << bool(frank) << endl;
    cout << franz.name << ": " << bool(franz) << endl;

    cout << boolalpha;



    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


