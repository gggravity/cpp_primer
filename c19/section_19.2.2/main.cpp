#include <bits/stdc++.h>
// #include "TextQuery.h"
// #include "QueryResult.h"
#include "AndQuery.h"
#include "BinaryQuery.h"
#include "OrQuery.h"
#include "Query.h"
#include "QueryBase.h"

using namespace std;

int main()
try
  {
    AndQuery and_query = AndQuery (Query ("fiery"), Query ("bird"));
    OrQuery or_query = OrQuery (Query ("fiery"), Query ("bird"));
    QueryBase *qb = new AndQuery (Query ("fiery"), Query ("bird"));

    QueryBase *pa {&and_query};
    QueryBase *po {&or_query};

    if (dynamic_cast<AndQuery *> (pa))
      {
        cout << "pa dynamic casted to AndQuery." << endl;
      }
    else
      {
        cout << "pa could not be dynamic casted to AndQuery." << endl;
      }

    if (dynamic_cast<AndQuery *> (po))
      {
        cout << "po dynamic casted to AndQuery." << endl;
      }
    else
      {
        cout << "po could not be dynamic casted to AndQuery." << endl;
      }

    if (dynamic_cast<AndQuery *> (qb))
      {
        cout << "qb dynamic casted to AndQuery." << endl;
      }
    else
      {
        cout << "qb could not be dynamic casted to AndQuery." << endl;
      }

    if (typeid (*pa) == typeid (*po))
      {
        cout << "The types are the same" << endl;
      }
    else
      {
        cout << "The types are different (" << typeid (*pa).name() << " and " << typeid (*po).name() << ")" << endl;
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
