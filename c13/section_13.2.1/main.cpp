#include "Str_blob.h"
#include <bits/stdc++.h>

using namespace std;

class HasPtr
{
public:

  explicit HasPtr (const string &s = string())
      : ps (new string (s)), i (0) {

                             };

  friend ostream &operator<< (ostream &os, const HasPtr &ptr)
  {
    os << "ps: " << *ptr.ps << " i: " << ptr.i << " &ps: " << ptr.ps;
    return os;
  }

  HasPtr (const HasPtr &rhs) : ps (new string {*rhs.ps}), i (rhs.i) { cout << "copy constructor called." << endl; }

  HasPtr &operator= (const HasPtr &rhs)
  {
    cout << "copy assignment constructor called." << endl;

    if (this == &rhs)  // is there any need of self-assignment.
      {
        return *this;
      }

    auto new_ps = new string {*rhs.ps};
    delete ps;
    ps = new_ps;
    i = rhs.i;

    return *this;
  };

  virtual ~HasPtr()
  {
    delete ps;
    cout << "ps deleted" << endl;
  }

private:

  string *ps {};
  int i {};
};

int main()
try
  {

    HasPtr h1 {"some string"};
    HasPtr h2 {h1};
    HasPtr h3 = h1;
    cout << h1 << endl;
    cout << h2 << endl;
    cout << h3 << endl;

    // 13.25
    // the string need to be copied on the copy and copy-assign constructors, else the pointers will point to the same
    // string. smart pointers are used, so no need for a destructor.
    Str_blob sb1 {"one", "two", "three"};
    Str_blob sb2 {sb1};
    sb2.push_back ("four");

    cout << sb1 << endl;
    cout << sb2 << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
