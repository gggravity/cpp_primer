#include "../section_12.3.2/QueryResult.h"
#include "TextQuery.h"
#include <bits/stdc++.h>

using namespace std;

ostream &print (ostream &os, const QueryResult &qr)
{
  auto pos {qr.word_to_lines->find (qr.query)};

  size_t times;

  if (pos != qr.word_to_lines->end())
    {
      times = pos->second.size();
    }
  else
    {
      times = 0;
    }

  os << qr.query << " occurs " << times << " times" << endl;

  for (auto &elem : pos->second)
    {
      cout << "(line " << elem << ") " << qr.lines->at (elem) << endl;
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
