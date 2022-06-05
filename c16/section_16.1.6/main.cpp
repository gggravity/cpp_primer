#include <bits/stdc++.h>
#include "UniquePointer.h"

using namespace std;

int main ()
try
  {
//    int *ptr = new int(10);
//    cout << *ptr << endl;
    UniquePointer<int> unique_pointer = new int(10);
    cout << *unique_pointer << endl;
    auto ptr = unique_pointer.release();
    cout << "*ptr: " << *ptr << endl;
//    cout << "*unique_pointer: " << *unique_pointer << endl;
    unique_pointer.reset(new int(999));
    cout << "*unique_pointer: " << *unique_pointer << endl;

    cout << "--- SWAP ---" << endl;

    UniquePointer<int> up1(new int(1));
    UniquePointer<int> up2(new int(2));

    up1.swap(up2);

    cout << "up1: " << *up1 << endl;
    cout << "up2: " << *up2 << endl;

    cout << "--- GET ---" << endl;

    UniquePointer<string> ups(new string { "Hello, world!" });
    auto res = ups.get();
    cout << *res << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


