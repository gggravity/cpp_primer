#include "Str_blob.h"
#include "Str_blob_ptr.h"
#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    Str_blob sb {"A", "B", "C", "D"};

    //    cout << sb[1] << endl;

    Str_blob_ptr sbp {sb};

    cout << "dereference: " << *sbp++ << endl;
    cout << "dereference: " << *sbp++ << endl;
    cout << "dereference: " << *sbp++ << endl;
    cout << "dereference: " << *sbp++ << endl;

    cout << "dereference: " << *--sbp << endl;
    cout << "dereference: " << *--sbp << endl;
    cout << "dereference: " << *--sbp << endl;
    cout << "dereference: " << *--sbp << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
