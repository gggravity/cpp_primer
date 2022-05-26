#include <bits/stdc++.h>
#include <ostream>
#include "Str_blob.h"
#include "Str_blob_ptr.h"
#include "Sales_data.h"

using namespace std;

class HasPtr
      {
      public:
            HasPtr (const string &s = string()) :
                ps(new string(s)),
                i(0)
              {

              };

            friend ostream &operator<< (ostream &os, const HasPtr &ptr)
              {
                os << "ps: " << *ptr.ps << " i: " << ptr.i;
                return os;
              }

            HasPtr (const HasPtr &rhs) :
                ps(new string { *rhs.ps }),
                i(rhs.i)
              {
                cout << "copy constructor called." << endl;
              }

            HasPtr &operator= (const HasPtr &rhs)
              {
                if (this == &rhs)
                  { //is there any need of self-assignment .
                    return *this;
                  }
                cout << "copy assignment constructor called." << endl;

                ps = new string { *rhs.ps };
                i = rhs.i;

                return *this;
              };

            virtual ~HasPtr ()
              {
                cout << "destroying has_prt" << endl;
              }

      private:
            string *ps { };
            int i { };
      };

void call_string_blob ()
  {
    Str_blob sb;
  }

void call_string_blob_ptr ()
  {
    Str_blob_ptr sbp;
  }

bool fcn (const Sales_data *trans, Sales_data accum)
  {
    Sales_data item1(*trans);
    Sales_data item2(accum);

    return item1.isbn() != item2.isbn();
  }

struct X
    {
        X () :
            x(0),
            y(0)
          {
            cout << "X()" << endl;
          }

        X (int x, int y) :
            x(x),
            y(y)
          {
            cout << "X()" << endl;
          }

        X (const X &)
          {
            cout << "X(const X&)" << endl;
          }

        X &operator= (const X &rhs)
          {
            cout << "operator=" << endl;

            return *this;
          }

        ~X ()
          {
            cout << "~X()" << endl;
          }

        int x;
        int y;
    };

int main ()
try
  {
    // e 13.10
//    call_string_blob();
//    call_string_blob_ptr();

    // e 13.11

//    HasPtr h;

    // e 13.12

//    auto sd1 { Sales_data { "1", 2, 3 } };
//    auto sd2 { Sales_data { "1", 2, 3 } };
//
//    cout << boolalpha;
//    bool eq;
//    eq = fcn(&sd1, sd2);
//    cout << eq << endl;

    // e 13.13

//    X x1;
//    X x2;
//
//    x1 = x2;
//
//    X x3 { x1 };

//    vector<X> v;
//    v.reserve(1000);
//
//    cout << "running for loop" << endl;
//
//    for (int i { 0 } ; i < 10 ; ++i)
//      {
//        cout << "iteration " << i << endl;
////        v.emplace_back();
//        v.push_back(X());
//      }
//    cout << "ending for loop" << endl;

    auto x = make_unique<X>(1, 2);

    vector<unique_ptr<X>> v;
    v.reserve(1000);

    cout << "running for loop" << endl;

    for (int i { 0 } ; i < 10 ; ++i)
      {
        cout << "iteration " << i << endl;
//        v.emplace_back(make_unique<X>(1, 2));
        v.push_back(make_unique<X>(1, 2));
      }
    cout << "ending for loop" << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
