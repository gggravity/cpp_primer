#include <bits/stdc++.h>

using namespace std;

int main ()
try
  {
    // e 12.16
//    unique_ptr<string> p1 { new string { "Stegosaurus" } };
//    unique_ptr<string> p2 ( p1 );
//    unique_ptr p3;
//    p3 = p1;

    // e 12.17
    int ix { 1024 }, *pi { &ix }, *pi2 = new int { 2048 };
    typedef unique_ptr<int> IntP;

//    IntP p0 { ix }; // ix not on the heap.
    IntP p1 { pi };
    IntP p2 { pi2 };
    IntP p3 { &ix };
    IntP p4 { new int { 2048 } };
    IntP p5 { p2.get() };

    // e 12.18

    // it would cause trouble for the other pointers pointing to that memory location.

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


