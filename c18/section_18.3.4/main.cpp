#include <bits/stdc++.h>
#include <ostream>

using namespace std;

struct Base
   {
      void bar (int)
        {
          cout << "calling bar (int) ..." << endl;
        }

   protected:
      int ival { 0 };
   };

struct Derived1 : virtual public Base
   {
      void bar (char)
        {
          cout << "calling bar (char) ..." << endl;
        }

      void foo (char)
        {
          cout << "calling foo (char) ..." << endl;
        }

   protected:
      char cval { '1' };
   };

struct Derived2 : virtual public Base
   {
      void foo (int)
        {
          cout << "calling foo (int) ..." << endl;
        }

   protected:
      int ival { 2 };
      char cval { '2' };
   };

class VMI : public Derived1, public Derived2
   {
   public:
      VMI ()
        {
          cout << ival << endl; // calls Derived2
//          cout << cval << endl; // Member 'cval' found in multiple base classes of different types
          bar(1); // calling bar (char) ...
          bar('b'); // calling bar (char) ...
          foo(1); // Member 'foo' found in multiple base classes of different types
          foo('b'); // Member 'foo' found in multiple base classes of different types
        }
   };

int main ()
  {
    VMI vmi;

    return 0;
  }
