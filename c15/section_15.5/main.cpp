#include <bits/stdc++.h>

using namespace std;

class base
   {
   public:
      void pub_member ();

   protected:
      int prot_member ();

   private:
      char priv_member ();
   };

class sneaky : public base
   {
      friend void clobber (sneaky &);

      friend void clobber (base &);
   };

struct pub_derv : public base
    {
        int f ()
          {
            return prot_member();
          }

        char g ()
          {
            return priv_member();
          }
    };

struct protected_derv : protected base
    {
        int f1 ()
          {
            return prot_member();
          }
    };

struct private_derv : private base
    {
        int f1 ()
          {
            return priv_member();
          }
    };

struct derived_from_public : public pub_derv
    {
        int use_base ()
          {
            return prot_member();
          }
    };

struct derived_from_private : public private_derv
    {
        int use_base ()
          {
            return prot_member();
          }
    };

int main ()
try
  {
    pub_derv d1;
    private_derv d2;
    prot
    base *p = &d1;
    p = &d2;
    p = &d3;
    p = &dd1;
    p = &dd2;
    p = &dd3;


    ////////// A MESS //////////

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


