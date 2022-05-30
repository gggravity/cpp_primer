#include <bits/stdc++.h>

using namespace std;

int main ()
try
  {
    // e 14.52

//    struct long_double; // fix 1

    class small_int
       {
       public:
          explicit small_int (int i = 0) :
              val(i)
            {
              if (i < 0 || i > 255)
                {
                  throw out_of_range("Bad small_int value");
                }
            }

          explicit operator int () const
            {
              return int(val);
            }

//          small_int operator+ (const long_double &); // fix 2

       private:
          size_t val;
       };

    struct long_double
        {
//            long_double () = default; // fix 3
//            long_double (small_int); // fix 4
            long_double operator+ (const small_int &);
        };

    long_double operator+(long_double&, double);

    small_int si;
    long_double ld;
    ld = si + ld; // invalid operands to binary expression ('small_int' and 'long_double')
    ld = ld + si; // long_double operator+ (const small_int &);

    // fix 1..4 make the errors go away, but should probably not be used in any code.

    // e 14.53

    small_int s1;
    double d = s1 + 3.14; // nope -> Invalid operands to binary expression ('small_int' and 'double')

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


