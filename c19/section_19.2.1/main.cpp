#include <bits/stdc++.h>
#include <ostream>

using namespace std;

class A
   {
   public:
      A ()
        {

        }

      virtual ~A ()
        {

        }

      friend std::ostream &operator<< (ostream &os, const A &a)
        {
          os << "I am A";
          return os;
        }
   };

class B : public A
   {
   public:
      B ()
        {

        }

      virtual ~B ()
        {

        }
   };

class C : public B
   {
   public:
      C ()
        {

        }

      virtual ~C ()
        {

        }

      friend std::ostream &operator<< (ostream &os, const C &c)
        {
          os << "I am C";
          return os;
        }
   };

//class D : public B, public A // Direct base 'A' is inaccessible due to ambiguity: class D -> class B -> class A class D -> class
//   {
//   public:
//      D ()
//        { }
//
//      virtual ~D ()
//        {
//
//        }
//   };

int main ()
  {
//    // a
    A *pa = new C;
//    B *pb = dynamic_cast<B*>(pa);

    // b
//    B *pb = new B;
//    C *pc = dynamic_cast<C *>(pb);
//
//    // c
//    A *pa = new D; // Ambiguous conversion from derived class 'D' to base class 'A': class D -> class B -> class A class D -> class A
//    B *pb = dynamic_cast<B*>(pa);

    if (C *pc = dynamic_cast<C *>(pa)) // Condition is always true
      {
        cout << *pc << endl;
      }
    else
      {
        cout << *pa << endl;
      }

    return 0;
  }
