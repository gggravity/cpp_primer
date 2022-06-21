#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    // page 481 version

    //    istringstream iss { "a b c d e f g" };
    //    int n = 100;
    //
    //    auto *const p = new string[n];
    //    string s;
    //    string *q = p;
    //
    //    while (iss >> s && q != p + n)
    //      {
    //        *q++ = s;
    //      }
    //
    //    const size_t size = q - p;
    //    // use the array
    //
    //    for (auto ptr = p ; ptr < p + size ; ptr++)
    //      {
    //        cout << *ptr << " ";
    //      }
    //
    //    delete[] p;

    // e 12.26

    // allocator.construct deprecated in c++20, skipping.
    // https://stackoverflow.com/questions/39414610/why-are-are-stdallocators-construct-and-destroy-functions-deprecated-in-c17

    istringstream iss {"a b c d e f g"};
    int n = 100;

    //    auto *const p = new string[n];
    allocator_traits<string> allocator;
    auto p = allocator.allocate (n);
    string s;
    string *q = p;

    while (iss >> s && q != p + n)
      {
        //        *q++ = s;
        allocator.construct (*p++);
      }

    const size_t size = q - p;
    // use the array

    for (auto ptr = p; ptr < p + size; ptr++)
      {
        cout << *ptr << " ";
      }

    delete[] p;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
