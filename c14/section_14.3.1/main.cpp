#include "Str_blob.h"
#include "Str_blob_ptr.h"
#include "String.h"
#include "string_vector.h"
#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    cout << boolalpha;

    // the below are comparing memory addresses and not content.

    cout << "--- Str_blob ---" << endl;

    Str_blob str_blob1 {"one", "two", "tree"};
    Str_blob str_blob2 {"A", "B", "C"};
    Str_blob str_blob3 {"A", "B", "C"};

    cout << (str_blob1 == str_blob2) << endl;
    cout << (str_blob1 != str_blob2) << endl;
    cout << (str_blob2 == str_blob2) << endl;
    cout << (str_blob2 == str_blob3) << endl;

    cout << "--- Str_blob_ptr ---" << endl;

    Str_blob_ptr str_blob_ptr1 {str_blob1};
    Str_blob_ptr str_blob_ptr2 {str_blob2};
    Str_blob_ptr str_blob_ptr3 {str_blob3};

    cout << (str_blob_ptr1 == str_blob_ptr2) << endl;
    cout << (str_blob_ptr1 != str_blob_ptr2) << endl;
    cout << (str_blob_ptr2 == str_blob_ptr2) << endl;
    cout << (str_blob_ptr2 == str_blob_ptr3) << endl;

    cout << "--- String ---" << endl;

    String string1 {"some string"};
    String string2 {"another string"};
    String string3 {"another string"};

    cout << (string1 == string2) << endl;
    cout << (string1 != string2) << endl;
    cout << (string2 == string2) << endl;
    cout << (string2 == string3) << endl;

    cout << "--- string_vector ---" << endl;

    string_vector sv1 {"one", "two", "tree"};
    string_vector sv2 {"A", "B", "C"};
    string_vector sv3 {"A", "B", "C"};

    cout << (sv1 == sv2) << endl;
    cout << (sv1 != sv2) << endl;
    cout << (sv2 == sv2) << endl;
    cout << (sv2 == sv3) << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
