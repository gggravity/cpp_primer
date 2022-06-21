#include "QueryResult.h"
#include "TextQuery.h"
#include <bits/stdc++.h>

using namespace std;

ostream &print (ostream &os, const QueryResult &qr)
{
  os << qr.sought << " occurs " << qr.lines->size() << " " << (qr.lines->size() > 1 ? "times" : "time") << endl;

  for (auto &num : *qr.lines)
    {
      os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + long (num)) << endl;
    }

  return os;
}

void runQueries (ifstream &infile)
{
  TextQuery tq (infile);

  while (true)
    {
      cout << "enter word to look for, or q to quit: ";
      string s;

      if (! (cin >> s) || s == "q")
        {
          break;
        }

      print (cout, tq.query (s)) << endl;
    }
}

int main()
try
  {
    ifstream ifs {"../text.txt"};
    runQueries (ifs);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
