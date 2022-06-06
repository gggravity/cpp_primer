#include <bits/stdc++.h>
#include <ostream>

using namespace std;

template < typename T >
string debug_rep (const T &t)
  {
    ostringstream ret;
    ret << t;
    return ret.str();
  }

template < typename T >
string debug_rep (T *p)
  {
    ostringstream ret;
    ret << "pointer: " << p;
    if (p)
      {
        ret << " " << debug_rep(*p);
      }
    else
      {
        ret << " null pointer";
      }
    return ret.str();
  }

string debug_rep (const string &s)
  {
    return '"' + s + '"';
  }

string debug_rep (char *p)
  {
    return debug_rep(string(p));
  }

string debug_rep (const char *p)
  {
    return debug_rep(string(p));
  }

template < typename T >
ostream &print (ostream &os, const T &t)
  {
    return os << t;
  }

template < typename T, typename... Args >
ostream &print (ostream &os, const T &t, const Args &... rest)
  {
    os << t << ", ";
    return print(os, rest...);
  }

template < typename ... Args >
ostream &errorMsg (ostream &os, const Args &...rest)
  {
    return print(os, debug_rep(rest)...);
  }

void error_msg (ostream &os, initializer_list<string> il)
  {
    for (auto ptr { il.begin() } ; ptr != il.end() ; ++ptr)
      {
        os << *ptr << " ";
      }
    os << endl;
  }

int main ()
try
  {
    errorMsg(cerr, "Error 1", "Error 2", "Error 3", "Error 4", "Error 5") << endl;

    error_msg(cerr, { "Error 1", "Error 2", "Error 3", "Error 4", "Error 5" } );

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


