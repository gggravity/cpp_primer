#include <bits/stdc++.h>

// not working on windows
// allocator not working with c++20

using namespace std;

void *operator new (size_t size)
  {
    if (void *mem = malloc(size))
      {
        cout << "calling new..." << endl;
        return mem;
      }
    else
      {
        throw bad_alloc();
      }
  }

void operator delete (void *mem) noexcept
  {
    cout << "calling delete... " << endl;
    free(mem);
  }

#include "string_vector.h"

int main ()
  {
    auto ptr = new string("Hello World!");

    cout << *ptr << endl;

    delete ptr;

    auto sv_ptr = new string_vector { "A", "B", "C" };

    for (auto iter = sv_ptr->begin() ; iter != sv_ptr->end() ; iter++)
      {
        cout << *iter << " ";
      }
    cout << endl;

    delete sv_ptr;

    return 0;
  }
