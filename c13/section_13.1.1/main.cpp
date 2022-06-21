#include "Str_blob.h"
#include "Str_blob_ptr.h"
#include <bits/stdc++.h>
#include <ostream>

using namespace std;

struct Point
{
  int x {0};
  int y {0};

  Point() : x (0), y (0) { cout << "Point constructed" << endl; };

  Point (int x, int y) : x (x), y (y) { cout << "Point constructed" << endl; };

  Point (const Point &) { cout << "Point copied" << endl; };
};

/*Point global;

Point foo_bar (const Point &arg) // no copying, copy without &
  {
    Point local = arg; // copying
    auto *heap = new Point(global); // copying
    *heap = local; // no copying
    Point pa[4] = { local, *heap }; // copying twice and constructing twice
    return *heap; // copying
//    return {}; // construct no copy
  }*/

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

private:

  string *ps {};
  int i {};
};

int main()
try
  {

    // e 13.3
    /*
    Str_blob str_blob;

    for (int i { 0 } ; i < 10 ; ++i)
      {
        str_blob.push_back("val" + to_string(i));
      }

    Str_blob_ptr str_blob_ptr { str_blob };

    auto sb = str_blob;
    auto sbp = str_blob_ptr;

    for (int i { 0 } ; i < sb.size() ; sbp.increment(), ++i)
      {
        cout << i << ": " << sbp.dereference() << endl;
      }
*/
    // e 13.4

    /*
    Point point;

    auto p = foo_bar(point);
    cout << p.x << " " << p.y << endl;
*/
    // e 13.5

    string s {"some string....."};
    auto hp = HasPtr {s};

    cout << hp << endl;

    const auto &hp_no_copy = hp;
    cout << hp_no_copy << endl;

    auto hp_copy = hp;
    cout << hp_copy << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
