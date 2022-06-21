#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    // e 14.50
    struct long_double
    {
      long_double (double = 0.0);  // Clang-Tidy: Single-argument constructors must be marked explicit to avoid
                                   // unintentional implicit conversions
      operator double();  // Clang-Tidy: 'operator double' must be marked explicit to avoid unintentional implicit
                          // conversions
      operator float();   // Clang-Tidy: 'operator float' must be marked explicit to avoid unintentional implicit
                          // conversions
    };

    long_double ld_obj;
    int ex1 = ld_obj;  // Conversion from 'long_double' to 'int' is ambiguous
    float ex2 = ld_obj;

    // e 14.51

    void calc (int);
    void calc (long_double);
    double d_val;
    calc (d_val);  // Clang-Tidy: Narrowing conversion from 'double' to 'int'

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
