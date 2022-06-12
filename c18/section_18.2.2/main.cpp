#include <bits/stdc++.h>

using namespace std;

namespace Exercise
  {
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
  }

int ivar = 0;
// position 1
//using Exercise::limit;


void manip()
  {
    // position 2
//    using Exercise::limit;
//    using Exercise::ivar;
    using Exercise::ivar;
    using namespace Exercise;
    double dvar = 3.1516;
    int iobj = limit + 1;
    ++ivar;
    ++::ivar;
  }

int main ()
  {
    manip();

    cout << "ival: " << ivar << endl;


    return 0;
  }
