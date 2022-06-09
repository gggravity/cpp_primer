#include <bits/stdc++.h>

using namespace std;

int main ()
try
  {
    string pattern { "[^c]ei" };
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";

    regex r { pattern, regex::icase };

    smatch results;

    string test_string { "receipt freind theif receive" };

//    if (regex_search(test_string, results, r))
//      {
//        cout << results.str() << endl;
//      }

    for (sregex_iterator it { test_string.begin(), test_string.end(), r }, end_it ; it != end_it ; ++it)
      {
        cout << it->str() << endl;
      }
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


