#include <bits/stdc++.h>

using namespace std;

int main ()
try
  {
    ifstream ifs { "../test_file.txt" };

    char line[1000];

    while (ifs.getline(line, 1000, ' '))
      {
        cout << line << endl;
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


