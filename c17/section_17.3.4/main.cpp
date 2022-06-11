#include <bits/stdc++.h>

using namespace std;

int main ()
try
  {
/*    istringstream iss {
        "morgan (201) 555-0168 862-555-0123\ndrew (973)555-0130\nlee (609) 555-0132 2015550175 800.555-0100\n" };

    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r { phone };;
    smatch m;
    string s;

    string fmt { "$2.$5.$7" };

    while (getline(iss, s))
      {
        cout << regex_replace(s, r, fmt) << endl;
      }*/
/*
    istringstream iss {
        "morgan (201) 555-0168 862-555-0123\ndrew (973)555-0130\nlee (609) 555-0132 2015550175 800.555-0100\n" };

    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r { phone };;
    smatch match;
    string str;

    string fmt { "$2.$5.$7" };

    while (getline(iss, str))
      {
        regex_search(str, match, r);

        if (!match.empty())
          {
            cout << match.prefix() << match.format(fmt) << endl;
          }
          else
          {
            cerr << "No matches" << endl;
          }
      }
*/

/*    istringstream iss {
        "morgan (201) 555-0168 862-555-0123\n"
        "drew (973)555-0130\n"
        "lee (609) 555-0132 2015550175 800.555-0100\n" };

    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r { phone };;
    smatch match;
    string str;

    string fmt { "$2.$5.$7" };

    while (getline(iss, str))
      {
        regex_search(str, match, r);

        if (!match.empty())
          {
            if (!match.suffix().matched)
              {
                cout << match.prefix() << match.format(fmt) << endl;
              }
            else
              {
                cout << match.prefix() << regex_replace(match.suffix().str(), r, fmt) << endl;
              }
          }
        else
          {
            cerr << "No matches" << endl;
          }
      }*/

    istringstream iss { "123456789\n987654321\n123123123\n" };
    string phone = "(\\d{5})(\\d{4})";
    regex r { phone };;
    smatch match;
    string str;

    string fmt { "$1-$2" };

    while (getline(iss, str))
      {
        regex_search(str, match, r);

        if (!match.empty())
          {
            cout << match.format(fmt) << endl;
          }
        else
          {
            cerr << "No matches..." << endl;
          }

      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


