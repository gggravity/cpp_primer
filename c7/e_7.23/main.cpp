#include "Screen.h"
#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
try
  {
    Screen screen {600, 400, 'X'};
    auto ch = screen.get (0, 0);

    cout << ch << endl;
    cout << screen.get() << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
