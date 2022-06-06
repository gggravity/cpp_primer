#include <bits/stdc++.h>
#include <ostream>

using namespace std;

template < typename T >
ostream &print (ostream &os, const T &t)
  {
    return os << t;
  }

template < typename T, typename... Args >
ostream &print (ostream &os, const T &t, const Args &... rest)
  {
    os << t << ", ";
    return print(os, rest...);
  }

struct Test
    {
        int i;
        int j;
    };

ostream &operator<< (ostream &os, const Test &test)
  {
    os << "i: " << test.i << " j: " << test.j;
    return os;
  }

int main ()
try
  {
    Test test1 { 1, 2 };
    Test test2 { 3, 4 };
    Test test3 { 5, 6 };
    Test test4 { 7, 8 };

    print(cout, 1, 2, 3, 4, 5) << endl;

    print(cout, &test1, &test2, &test3, &test4) << endl;

    // error: invalid operands to binary expression ('std::ostream' (aka 'basic_ostream<char>') and 'const Test')
    // need operator<<
    print(cout, test1, test2, test3, test4) << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


