#include "Token.h"
#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    Token token;

    token = 123;

    cout << token << endl;

    token = 'A';

    cout << token << endl;

    token = string ("Hello World!!!");

    cout << token << endl;

    token = 123.123f;

    cout << token << endl;

    token = SalesData {"123-XXX", 1, 1};

    cout << token << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
