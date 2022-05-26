#include <bits/stdc++.h>

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
                os << "ps: " << *ptr.ps << " i: " << ptr.i << " &ps: " << ptr.ps;
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
                if (this == &rhs) //is there any need of self-assignment.
                  {
                    return *this;
                  }
                cout << "copy assignment constructor called." << endl;

                ps = new string { *rhs.ps };
                i = rhs.i;

                return *this;
              };

            virtual ~HasPtr ()
              {
                delete ps;
                cout << "destroying has_prt" << endl;
              }

      private:
            string *ps { };
            int i { };
      };

int main ()
try
  {

    HasPtr h1 { "some string" };
    HasPtr h2 { h1 };
    HasPtr h3 = h1;
    cout << h1 << endl;
    cout << h2 << endl;
    cout << h3 << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
