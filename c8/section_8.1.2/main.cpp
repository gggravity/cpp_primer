#include <bits/stdc++.h>

using namespace std;

istream &print(istream &is)
  {
    string temp;
    is >> temp;
    cout << "Read: " << temp << endl;
    return is;
  }

int main ()
try
  {

    print(cin);

    // e 8.3 - failed state.

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
