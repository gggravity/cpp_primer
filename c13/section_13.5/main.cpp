#include <bits/stdc++.h>
#include "string_vector.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "String.h"

using namespace std;

ostream &print (ostream &os, const QueryResult &qr)
  {
    os << qr.sought << " occurs " << qr.lines->size() << " " << ( qr.lines->size() > 1 ? "times" : "time" ) << endl;

    for (auto &num : *qr.lines)
      {
        os << "\t(line " << num + 1 << ") " << *( qr.file->begin() + long(num) ) << endl;
      }

    return os;
  }

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

    String ss;

    ss = "testing ....";

    cout << ss << endl;

    String cs {"test string..."};

    cout << cs << endl;

    String sss {string {"c++ string"}};

    cout << sss << endl;

    cout << sss.capacity() << endl;

    sss.reserve(100);

    cout << sss.capacity() << endl;

    cout  << "-------------------------------------------------------------" << endl;

    string_vector sv;

    sv.push_back("some string");
    sv.push_back("another string");
    sv.push_back("one more string");
    sv.push_back("last string");

    cout << sv.capacity() << endl;
    sv.reserve(100);
    cout << sv.capacity() << endl;

    for (auto ptr = sv.begin() ; ptr != sv.end() ; ++ptr)
      {
        cout << *ptr << " ";
      }

    cout << endl;

    for (auto &s : sv)
      {
        cout << s << " ";
      }

    cout << endl;

    string_vector ilsv { "one", "two", "three" };

    for (auto &s : ilsv)
      {
        cout << s << endl;
      }

    cout << endl << "-------------------------------------------------------------" << endl;

    ifstream ifs { "../text.txt" };
    runQueries(ifs);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
