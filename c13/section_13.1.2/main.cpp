#include "Str_blob.h"
#include "Str_blob_ptr.h"
#include <bits/stdc++.h>
#include <ostream>

using namespace std;

class HasPtr
{
public:

  HasPtr (const string &s = string())
      : ps (new string (s)), i (0) {

                             };

  friend ostream &operator<< (ostream &os, const HasPtr &ptr)
  {
    os << "ps: " << *ptr.ps << " i: " << ptr.i;
    return os;
  }

  HasPtr (const HasPtr &rhs) : ps (new string {*rhs.ps}), i (rhs.i) { cout << "copy constructor called." << endl; }

  HasPtr &operator= (const HasPtr &rhs)
  {
    if (this == &rhs)
      {  // is there any need of self-assignment .
        return *this;
      }
    cout << "copy assignment constructor called." << endl;

    ps = new string {*rhs.ps};
    i = rhs.i;

    return *this;
  };

private:

  string *ps {};
  int i {};
};

int main()
try
  {

    // e 13.7

    Str_blob sb_1, sb_2;

    for (int i {0}; i < 10; ++i)
      {
        sb_1.push_back ("val" + to_string (i));
        sb_2.push_back ("val" + to_string (i * i));
      }

    //    sb_2 = sb_1;

    //    cout << "---------" << endl;

    Str_blob_ptr sbp_1 {sb_1};
    Str_blob_ptr sbp_2 {sb_2};

    //    sbp_2 = sbp_1;

    for (int i {0}; i < sb_1.size(); sbp_1.increment(), ++i)
      {
        cout << i << ": " << sbp_1.dereference() << " ";
      }

    cout << endl;

    for (int i {0}; i < sb_1.size(); sbp_2.increment(), ++i)
      {
        cout << i << ": " << sbp_2.dereference() << " ";
      }

    // e 13.8

    string s {"some string....."};
    auto hp = HasPtr {s};

    cout << hp << endl;

    const auto &hp_no_copy = hp;
    cout << hp_no_copy << endl;

    auto hp_copy = hp;
    cout << hp_copy << endl;

    HasPtr hp2 {string {"xxx"}};
    hp = hp2;
    cout << hp << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
