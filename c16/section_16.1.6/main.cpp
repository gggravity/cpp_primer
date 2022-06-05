#include <bits/stdc++.h>
#include "UniquePointer.h"
#include "SharedPointer.hpp"
#include "Blob.h"

using namespace std;

int main ()
try
  {
//    UniquePointer<int> unique_pointer = new int(10);
//    cout << *unique_pointer << endl;
//    auto ptr = unique_pointer.release();
//
//    if (unique_pointer)
//      {
//        cout << "*unique_pointer: " << *unique_pointer << endl;
//      }
//    else
//      {
//        cout << "pointer is empty" << endl;
//      }
//
//    unique_pointer.reset(new int(999));
//    cout << "*unique_pointer: " << *unique_pointer << endl;
//
//    cout << "--- SWAP ---" << endl;
//
//    UniquePointer<int> up1(new int(1));
//    UniquePointer<int> up2(new int(2));
//
//    up1.swap(up2);
//
//    cout << "up1: " << *up1 << endl;
//    cout << "up2: " << *up2 << endl;
//
//    cout << "--- GET ---" << endl;
//
//    UniquePointer<string> ups(new string { "Hello, world!" });
//    auto res = ups.get();
//    cout << *res << endl;

//    SharedPointer<int> sp1 = new int(10);
//    auto s = new string { "pointer string" };
//    shared_ptr<string> sp1 { s, DebugDelete() };
//    shared_ptr<string> sp2 { sp1 };
//    shared_ptr<string> sp3 { sp2 };
//
//    cout << sp1.use_count() << endl;
//
//    cout << sp2.use_count() << endl;
//    cout << sp3.use_count() << endl;

//    auto s = new string { "pointer string" };
//    SharedPointer<string> sp1 { s, DebugDelete() };
//    SharedPointer<string> sp2 { sp1 };
//    SharedPointer<string> sp3 { sp2 };
//
//    cout << sp1.use_count() << endl;
//    cout << sp2.use_count() << endl;
//    cout << sp3.use_count() << endl;

    Blob blob1 { "A", "B", "C" };
    Blob blob2 { 1, 2, 3 };

    cout << blob1 << endl;
    cout << blob2 << endl;


    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


