#include <bits/stdc++.h>
#include "quote.h"
#include "bulk_quote.h"
#include "discount_quote.h"

using namespace std;

class base
   {
   public:
      string name ()
        {
          return basename;
        }

      virtual void print (ostream &os)
        {
          os << basename;
        }

   private:
      string basename { "basename" };
   };

class derived : public base
   {
   public:
      void print (ostream &os) override
        {
          os << " ";
          base::print(os);
          os << " " << i << endl;
        }

   private:
      int i { 10 };
   };

int main ()
try
  {
    // e 15.11

    quote q;
    bulk_quote bq;
    discount_quote dq;

    q.debug();
    bq.debug();
    dq.debug();

    // 15.13

    base b;
    derived d;

    b.print(cout);
    d.print(cout);

    // 15.14

    base bobj;
    base *bp1 = &bobj;
    base &br1 = bobj;
    derived dobj;
    derived *bp2 = &dobj;
    derived &br2 = dobj;

    bobj.print(cout); // runtime
    dobj.print(cout); // runtime
    cout << bp1->name() << endl;
    cout << bp2->name() << endl;
    br1.print(cout);
    br2.print(cout);



    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


