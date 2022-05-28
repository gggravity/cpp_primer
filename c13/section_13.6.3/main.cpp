#include <bits/stdc++.h>
#include "Str_blob.h"

using namespace std;

class Foo
   {
   public:
      Foo sorted () &&;

      Foo sorted () const &;

      Foo add (size_t i);

      friend ostream &operator<< (ostream &os, const Foo &foo);

   private:
      vector<int> data;
   };

Foo Foo::sorted () &&
  {
    cout << "calling: Foo Foo::sorted () &&" << endl;
    sort(data.begin(), data.end());
    return *this;
  }

//Foo Foo::sorted () const &
//  {
//    cout << "calling: Foo Foo::sorted () const &" << endl;
//    Foo ret { *this };
//    sort(ret.data.begin(), ret.data.end());
//    return ret;
//  }

//Foo Foo::sorted () const &
//  {
//    cout << "calling: Foo Foo::sorted () const &" << endl;
//    Foo ret { *this };
////    sort(ret.data.begin(), ret.data.end());
//    return ret.sorted();
//  }

Foo Foo::sorted () const &
  {
    cout << "calling: Foo Foo::sorted () const &" << endl;
    return Foo(*this).sorted();
  }

Foo Foo::add (size_t i)
  {
    data.emplace_back(i);
    return *this;
  }

ostream &operator<< (ostream &os, const Foo &foo)
  {
    os << "data: ";
    for (auto &i : foo.data)
      {
        cout << i << " ";
      }
    return os;
  }

int main ()
try
  {
    Foo foo;

    for (size_t i { 10 } ; i >= 1 ; --i)
      {
        foo.add(i);
      }

    cout << foo << endl;
    foo = foo.sorted();
    cout << foo << endl;
    cout << foo.add(1).add(2).add(3).sorted() << endl;

    // e 13.56
    // inf recursion.

    // e 13.57
    // works :-)

    // e 13.58
    // see operator<<

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
