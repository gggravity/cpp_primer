#include <bits/stdc++.h>
// #include "TextQuery.h"
// #include "QueryResult.h"
#include "AndQuery.h"
#include "BinaryQuery.h"
#include "OrQuery.h"
#include "Query.h"

using namespace std;

/*ostream &print (ostream &os, const QueryResult &query_result)
  {
    os << query_result.sought << " occurs " << query_result.lines->size() << " "
       << ( query_result.lines->size() > 1 ? "times" : "time" ) << endl;

    for (auto &num : *query_result.lines)
      {
        os << "\t(line " << num + 1 << ") " << *( query_result.file->begin() + long(num) ) << endl;
      }

    return os;
  }

void runQueries (ifstream &infile)
  {
    TextQuery text_query(infile);

    while (true)
      {
        cout << "enter word to look for, or q to quit: ";
        string s;

        if (!( cin >> s ) || s == "q")
          {
            break;
          }

        print(cout, text_query.query(s)) << endl;
      }

  }*/

int main()
try
  {

    //    ifstream ifs { "../text.txt" };
    //    runQueries(ifs);

    string sought1 {"Alice"};
    string sought2 {"bird"};

    Query and_query = Query (sought1) & Query (sought2);
    cout << and_query << endl;

    Query not_query = ~Query (sought1);
    cout << not_query << endl;

    Query or_query = Query (sought1) | Query (sought2);
    cout << or_query << endl;

    cout << "----------------------" << endl;

    //    BinaryQuery a = Query("fiery") & Query("bird"); // Not ok, abstract base class
    //    AndQuery b = Query("fiery") & Query("bird");
    //    OrQuery c = Query("fiery") & Query("bird"); // error: conversion from ‘Query’ to non-scalar type ‘OrQuery’
    //    requested

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
