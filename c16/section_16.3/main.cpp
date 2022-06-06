#include <bits/stdc++.h>

using namespace std;

template < typename T >
string debug_rep (const T &t)
  {
    cout << "(const T &t)";
    ostringstream ret;
    ret << t;
    return ret.str();
  }

template < typename T >
string debug_rep (T *p)
  {
    cout << "(T *p)";
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
    cout << "(const string &s)";
    return '"' + s + '"';
  }

string debug_rep (char *p)
  {
    cout << "(char *p)";
    return debug_rep(string(p));
  }

string debug_rep (const char *p)
  {
    cout << "(const char *p)";
    return debug_rep(string(p));
  }

template < typename T >
void f (T t)
  {
    cout << "f (T t): " << t << endl;
  }

template < typename T >
void f (const T *t)
  {
    cout << "f (const T *t): " << t << endl;
  }

template < typename T >
void g (T t)
  {
    cout << "g (T t): " << t << endl;
  }

template < typename T >
void g (T *t)
  {
    cout << "g (T *t): " << t << endl;
  }

int main ()
try
  {
    string s { "debug string" };

    int ia[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

//    cout << debug_rep(ia) << endl;

/*    int i { 42 };
    int *p { &i };
    const int ci { 0 };
    const int *p2 { &ci };

    g(42); // call g (T t)
    g(p); // call g(T *t)
    g(ci); // call g(T t)
    g(p2); // call g(T *t)

    f(42); // call f(T t)
    f(p); // call f(T t)
    f(ci); // call f(T t)
    f(p2); // call f(const T *t)*/

    cout << debug_rep(s) << endl;

    cout << debug_rep(&s) << endl;

    cout << debug_rep(ia) << endl;

    cout << debug_rep("hi world!") << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


