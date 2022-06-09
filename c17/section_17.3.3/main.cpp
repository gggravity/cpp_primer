#include <bits/stdc++.h>

using namespace std;

auto valid (const smatch &m)
  {
    if (m[1].matched)
      {
        return m[3].matched && ( m[4].matched == 0 || m[4].str() == " " );
      }
    else
      {
        return !m[3].matched && m[4].str() == m[6].str();
      }
  }

int main ()
try
  {
//    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    string phone = "(\\()?(\\d{3})(\\))?([-. ])*(\\d{3})([-. ]?)(\\d{4})";
    regex r { phone };
    smatch m;
    string s;

    istringstream iss {
        "123.123.1234\n (321) 321 3210\n4212.432.432\n (123-123-3213\n (123)-123.1234\n (123) 123-1234\n (123)    123-1234\n (123) 123-1234\n" };

    while (getline(iss, s))
      {
        for (sregex_iterator it { s.begin(), s.end(), r }, end_it ; it != end_it ; ++it)
          {
            if (valid(*it))
              {
                cout << "valid: " << it->str() << endl;
              }
            else
              {
                cout << "not valid: " << it->str() << endl;
              }
          }
      }
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


