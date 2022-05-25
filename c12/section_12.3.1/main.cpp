#include <bits/stdc++.h>
#include "TextQuery.h"

using namespace std;

void runQueries (ifstream &infile)
  {
    TextQuery tq(infile);

    while (true)
      {
        cout << "enter word to look for, or q to quit: ";
        string s;

        if (!( cin >> s ) || s == "q")
          {
            break;
          }

        print(cout, tq.query(s)) << endl;
      }

  }

int main ()
try
  {
    ifstream ifs { "../text.txt" };
    runQueries(ifs);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


