#include <bits/stdc++.h>

using namespace std;

class Debug
      {
      public:
            constexpr Debug (bool b = true)
                : hw(b),
                  io(b),
                  other(b)
              {

              }

            constexpr Debug (bool h, bool i, bool o)
                : hw(h),
                  io(i),
                  other(o)
              {

              }

            [[nodiscard]] constexpr bool any () const
              {
                return hw || io || other;
              }

            void set_io (bool b)
              {
                io = b;
              };

            void set_hw (bool b)
              {
                hw = b;
              };

            void set_other (bool b)
              {
                other = b;
              };

      private:
            bool hw;
            bool io;
            bool other;
      };

int main ()
try
  {
    constexpr Debug io_sub { false, true, false };

    if (io_sub.any())
      {
        cerr << "Print appropriate error message" << endl;
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
