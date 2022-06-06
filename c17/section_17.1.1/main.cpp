#include <bits/stdc++.h>
#include "TextQuery.h"

using namespace std;

int main ()
try
  {
    /*
    tuple<int, int, int> t { 10, 20, 30 };

    cout << get<0>(t) << endl;
    cout << get<1>(t) << endl;
    cout << get<2>(t) << endl;

    vector<string> vs { "1", "2", "3", "4" };
    pair<string, int> psi { "yellow world", 123 };

    tuple<string, vector<string>, pair<string, int>> t2 {"Hello World!", vs, psi};

    cout << get<0>(t2) << endl;
    cout << &get<1>(t2) << endl;
    cout << &get<2>(t2) << endl;
    */

    ifstream ifs { "../text.txt" };
    runQueries(ifs);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


