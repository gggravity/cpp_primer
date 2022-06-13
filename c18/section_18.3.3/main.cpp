#include <bits/stdc++.h>

using namespace std;

struct Base1
   {
      virtual void print (int i)
        {
          cout << "print(int): " << i << endl;
        }

   protected:
      int ival;
      double dval;
      char cval;

   private:
      int *id;
   };

struct Base2
   {
      void print (double d)
        {
          cout << "print(double): " << d << endl;
        }

   protected:
      double fval;

   private:
      double dval;
   };

struct Derived : public Base1
   {
      void print (const string &s)
        {
          cout << "print(string): " << s << endl;
        }

   protected:
      string sval;
      double dval { };
   };

struct MI : public Derived, public Base2
   {
      void print (vector<double> vd)
        {
          cout << "print(vector<double>): " << &vd << endl;
        }

      void print (int i)
        {
          Derived::Base1::print(i);
        }

      int ival;
      double dval;

      void foo (double cval)
        {
          int dval;
        }

   protected:
      vector<double> dvec;
   };

int main ()
  {

    MI mi;
    mi.print(42); // No viable conversion from 'int' to 'vector<double>'

    return 0;
  }
