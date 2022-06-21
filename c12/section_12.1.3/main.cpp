#include <bits/stdc++.h>

using namespace std;

void process (const shared_ptr<int> &ptr) { cout << *ptr << endl; }

int main()
try
  {
    // e 12.10

    //    shared_ptr<int> p (new int(42));
    //    process(shared_ptr<int>(p)); // yes, but long. 42 go out of scope and a new int(42) are created.
    //    process(p);

    // e 12.11

    //    process(shared_ptr<int>(p.get())); // free(): double free detected in tcache 2

    // e 12.12

    //    auto p = new int(2);
    //    auto sp = make_shared<int>(1);
    //
    //    process(sp);
    //    // process(new int()); // illegal, not a shard pointer
    ////    process(p);  // illegal, not a shard pointer
    //    process(shared_ptr<int>(p)); // ok, deallocate sp' int and reallocate it to p's int.

    // e 12.13

    auto sp = make_shared<int> (123);
    auto p = sp.get();
    delete p;

    cout << *sp << endl;
    cout << sp.use_count() << endl;

    // double free or corruption (out)
    // delete p; will delete the memory, and it will be deleted again when sp go out of scope.

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
