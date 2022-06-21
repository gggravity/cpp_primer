#include "Str_blob.h"
#include "Str_blob_ptr.h"
#include "String.h"
#include "string_vector.h"
#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    Str_blob sb {"A", "B", "C"};

    cout << sb[1] << endl;

    Str_blob_ptr sbp {sb};

    cout << sbp[1] << endl;

    String s {"QWERTY"};

    cout << s[5] << endl;

    string_vector sv {"zero", "one", "two", "tree"};

    cout << sv[0] << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
